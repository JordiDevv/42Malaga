#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <iomanip>

  // **************************************************** //
 //                      Printers                        //
// **************************************************** //

	void charPrinter(const int& c)
	{
		std::cout << "char: ";

		if (c < 0 || c > 127) std::cout << "impossible";
		else if (!isprint(c)) std::cout << "Non displayable";
		else std::cout << (char)c;

		std::cout << std::endl;
	}

	void intPrinter(const int& n)
	{
		std::cout << "int: " << n << std::endl;
	}

	void floatPrinter(const float& f)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}


  // **************************************************** //
 //                       Flows                          //
// **************************************************** //

	void charFlow(char* c, int* n, float* f)
	{
		charPrinter(*c);
		*n = static_cast<int>(*c);
		intPrinter(*n);
		*f = static_cast<float>(*c);
		floatPrinter(*f);
	}

	void intFlow(char* c, int* n, float* f)
	{
		*c = static_cast<char>(*n);
		charPrinter(*c);
		intPrinter(*n);
		*f = static_cast<float>(*n);
		floatPrinter(*f);
	}

	void floatFlow(char* c, int* n, float* f)
	{
		*c = static_cast<char>(*f);
		charPrinter(*c);
		*n = static_cast<float>(*f);
		intPrinter(*n);
		floatPrinter(*f);
	}


  // **************************************************** //
 //                       Parser                         //
// **************************************************** //

	bool isChar(const std::string& literal)
	{ return (literal.length() == 1 && !isdigit(literal[0])); }

	bool inRange(const std::string& literal, const std::string& type)
	{
		errno = 0;
		char* end;

		if (type == "int")
		{
			long value = strtol(literal.c_str(), &end, 10);
			return (errno != ERANGE && value <= INT_MAX && value >= INT_MIN);
		}
		if (type == "float")
		{
			float value = strtof(literal.c_str(), &end);
			return (errno != ERANGE && value <= FLT_MAX && value >= -FLT_MAX);
		}
		double value = strtod(literal.c_str(), &end);
		return (errno != ERANGE && value <= DBL_MAX && value >= -DBL_MAX);
	}

	std::string isValid(const std::string& literal)
	{
		if (!isdigit(literal[0]) && literal[0] != '+' && literal[0] != '-')
			return "Not valid";
		int invalidDot = 1;

		for (unsigned int i = 1; i < literal.length(); i++)
		{
			if (!isdigit(literal[i]))
			{
				if (i + 1 == literal.length())
				{
					if (literal[i] == 'f' && !invalidDot && isdigit(literal[i - 1]))
						return "float";
					else return "Not valid";
				}
				if (literal[i] == '.') invalidDot--;
				if (invalidDot || literal[i] != '.') return "Not valid";
			}
		}

		return invalidDot ? "int" : "double";
	}

	std::string parser(const std::string& literal)
	{
		std::string type;

		if (isChar(literal)) type = "char";
		else
		{
			type = isValid(literal);
			if (type != "Not valid")
				if (!inRange(literal, type)) type = "Not valid";
		}
		return type;
	}

  // **************************************************** //
 //                  Converter method                    //
// **************************************************** //

	void ScalarConverter::convert(const std::string& literal)
	{
		std::string types[3] = { "char", "int", "float" };
		ConverterFlows converterFlows[3] = { charFlow, intFlow, floatFlow };

		std::string type;
		type = parser(literal);

		char *end;
		char c;
		int n;
		float f;

		if (type == "char") c = literal[0];
		else if (type == "int") n = atoi(literal.c_str());
		else if (type == "float") f = strtof(literal.c_str(), &end);

		for (int i = 0; i < 3; i++)
		{
			if (type == types[i])
			{
				converterFlows[i](&c, &n, &f);
				return ;
			}
		}
		std::cout << type << std::endl;
	}

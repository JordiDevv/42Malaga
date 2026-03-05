#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>

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


  // **************************************************** //
 //                       Flows                          //
// **************************************************** //

	void intFlow(const std::string& literal)
	{
		int n = atoi(literal.c_str());
		charPrinter(n);
		intPrinter(n);
	}

	void charFlow(const std::string& literal)
	{
		int c = literal[0];
		charPrinter(c);
		intPrinter(c);
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
		std::string types[2] = { "char", "int" };
		ConverterFlows converterFlows[2] = { charFlow, intFlow };

		std::string type;
		type = parser(literal);

		for (int i = 0; i < 2; i++)
		{
			if (type == types[i])
			{
				converterFlows[i](literal);
				return ;
			}
		}
		std::cout << type << std::endl;
	}

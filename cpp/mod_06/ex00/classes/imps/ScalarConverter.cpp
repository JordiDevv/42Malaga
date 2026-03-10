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

	void charPrinter(char c, bool possible)
	{
		std::cout << "char: ";

		if (!possible) std::cout << "impossible";
		else if (!isprint(c)) std::cout << "Non displayable";
		else std::cout << c;

		std::cout << std::endl;
	}

	void intPrinter(int n, bool possible)
	{
		std::cout << "int: ";

		if (!possible) std::cout << "impossible";
		else std::cout << n;

		std::cout << std::endl;
	}

	void floatPrinter(float f, bool possible)
	{
		std::cout << "float: ";

		if (!possible) std::cout << "impossible";
		else std::cout << std::fixed << std::setprecision(1) << f << "f";

		std::cout << std::endl;
	}

	void doublePrinter(double d, bool possible)
	{
		std::cout << "double: ";

		if (!possible) std::cout << "impossible";
		else std::cout << std::fixed << std::setprecision(1) << d;

		std::cout << std::endl;
	}

	void pseudoPrinter(std::string pseudo)
	{
		if (pseudo == "nanf" || pseudo == "inff" || pseudo == "-inff")
			pseudo.erase(pseudo.end() - 1);

		std::cout << "float: " << pseudo << "f" << std::endl;
		std::cout << "double: " << pseudo << std::endl;
	}


  // **************************************************** //
 //                       Flows                          //
// **************************************************** //

	void charFlow(char c, int n, float f, double d)
	{
		charPrinter(c, true);

		n = static_cast<int>(c);
		intPrinter(n, true);

		f = static_cast<float>(c);
		floatPrinter(f, true);

		d = static_cast<double>(c);
		doublePrinter(d, true);
	}

	void intFlow(char c, int n, float f, double d)
	{
		c = static_cast<char>(n);
		if (n < 0 || n > 127) charPrinter(c, false);
		else charPrinter(c, true);
		
		intPrinter(n, true);

		f = static_cast<float>(n);
		floatPrinter(f, true);

		d = static_cast<float>(n);
		doublePrinter(d, true);
	}

	void floatFlow(char c, int n, float f, double d)
	{
		c = static_cast<char>(f);
		if (f < 0 || f > 127) charPrinter(c, false);
		else charPrinter(c, true);

		n = static_cast<int>(f);
		if (f > INT_MAX || f < INT_MIN) intPrinter(n, false);
		else intPrinter(n, true);

		floatPrinter(f, true);

		d = static_cast<double>(f);
		doublePrinter(d, true);
	}

	void doubleFlow(char c, int n, float f, double d)
	{
		c = static_cast<char>(d);
		if (d < 0 || d > 127) charPrinter(c, false);
		else charPrinter(c, true);

		n = static_cast<float>(d);
		if (d > INT_MAX || d < INT_MIN) intPrinter(n, false);
		else intPrinter(n, true);

		f = static_cast<double>(d);
		if (d > FLT_MAX || d < -FLT_MAX) floatPrinter(f, false);
		else floatPrinter(f, true);
		
		doublePrinter(d, true);
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

	bool isPseudo(const std::string& literal)
	{
		const std::string pseudoLiterals [6] =
		{ "inf", "-inf", "inff", "-inff", "nan", "nanf"};

		for (int i = 0; i < 6; i++)
			if (literal == pseudoLiterals[i]) return true;
		return false;
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
		std::string types[4] = { "char", "int", "float", "double" };
		ConverterFlows converterFlows[4] = { charFlow, intFlow, floatFlow, doubleFlow };

		std::string type;
		if (isPseudo(literal))
		{
			type = literal;
			charPrinter(0, false);
			intPrinter(0, false);
			pseudoPrinter(literal);
		}
		else
		{
			type = parser(literal);

			char *end;
			char c;
			int n;
			float f;
			double d;

			if (type == "char") c = literal[0];
			else if (type == "int") n = atoi(literal.c_str());
			else if (type == "float") f = strtof(literal.c_str(), &end);
			else if (type == "double") d = strtod(literal.c_str(), &end);

			for (int i = 0; i < 4; i++)
			{
				if (type == types[i])
				{
					converterFlows[i](c, n, f, d);
					return ;
				}
			}
			std::cout << type << std::endl;
		}
	}

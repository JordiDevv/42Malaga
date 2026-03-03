#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <cstdlib>

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
 //                  Converter method                    //
// **************************************************** //

	std::string parser(const std::string& literal)
	{
		if (literal.length() == 1)
		{
			if (isdigit(literal.c_str()[0])) return "int";
			return "char";
		}
		return "Please, type any literal: char, int, float, or double";
	}

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

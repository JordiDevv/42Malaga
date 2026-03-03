#include "ScalarConverter.hpp"
#include <string>
#include <cctype>
#include <iostream>

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
	}

	void ScalarConverter::convert(const std::string& literal)
	{
		std::string type;
		type = parser(literal);
		std::cout << type << std::endl;
	}

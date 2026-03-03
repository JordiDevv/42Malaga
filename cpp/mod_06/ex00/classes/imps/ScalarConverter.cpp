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
		return "impossible";
	}

	void intFlow(const std::string& literal)
	{
		std::cout << literal << std::endl;
	}

	void charFlow(const std::string& literal)
	{
		std::cout << literal << std::endl;
	}

	void ScalarConverter::convert(const std::string& literal)
	{
		std::string types[2] = { "int", "char" };
		ConverterFlows converterFlows[2] = { intFlow, charFlow };

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

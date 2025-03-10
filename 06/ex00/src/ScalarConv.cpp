#include "ScalarConv.hpp"

static bool isChar(const std::string &s)
{
	return (s.size() == 1 && !std::isdigit(s[0]) && std::isprint(s[0]));
}

static bool isInt(const std::string &s)
{
	int i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
		if (!std::isdigit(s[i++]))
			return false;
	return true;
}

static bool isFloat(const std::string &s)
{
	int dot = 0, f = 0;
	int i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!std::isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
			return false;
		if (s[i] == '.')
			dot++;
		if (s[i] == 'f')
			f++;
		if (f > 1 || dot > 1)
			return false;
		i++;
	}
	if (s[s.size() - 1] != 'f')
		return false;
	return true;
}

static bool isDouble(const std::string &s)
{
	int dot = 0;
	int i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!std::isdigit(s[i]) && s[i] != '.')
			return false;
		if (s[i] == '.')
			dot++;
		if (dot > 1)
			return false;
		i++;
	}
	return true;
}

static bool isInf(const std::string &s)
{
	if (s == "-inff" || s == "+inff" ||
      s == "nanf" || s == "-inf" ||
      s == "+inf" || s == "nan")
    return true;
  return false;
}

static void		convertChar(const std::string &s) {
	std::cout << "char: " << s[0] << std::endl;
	std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(s[0]) << std::endl;
}

static void		convertInt(const std::string &s) {
	int	n = atoi(s.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void		convertFloat(const std::string &s) {
	float	n = atof(s.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(5) << n << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(5) << static_cast<double>(n) << std::endl;
}

static void		convertDouble(const std::string &s) {
	double	n = atof(s.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(5) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(5) << n << std::endl;
}

static void		convertMinInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

static void		convertMaxInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

static void		convertNan() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static void convertInf(const std::string &s)
{
	if (s == "-inf" || s == "-inff")
		convertMinInf();
	else if (s == "+inf" || s == "+inff")
		convertMaxInf();
	else if (s == "nan" || s == "nanf")
		convertNan();
}

void ScalarConv::convert(const std::string &input)
{
	if (isChar(input))
		convertChar(input);
	else if (isInt(input))
		convertInt(input);
	else if (isFloat(input))
		convertFloat(input);
	else if (isDouble(input))
		convertDouble(input);
	else if (isInf(input))
		convertInf(input);
	else
		std::cout << "Unkown type" << std::endl;
}
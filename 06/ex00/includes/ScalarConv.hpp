#ifndef SCALARCONV_HPP
# define SCALARCONV_HPP

#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <climits>
#include <float.h>
#include <cstdlib>

class ScalarConv
{
public:

	static void	convert(const std::string &input);

private:

// ----------------------------- Constructors ------------------------------ //
	ScalarConv();	// Default Constructor
	ScalarConv(const ScalarConv& c);	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
	~ScalarConv();	// Destructor

// ------------------------------- Operators ------------------------------- //
	ScalarConv & operator=(const ScalarConv& a);
	// Copy Assignement Operator
};

#endif

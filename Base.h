#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

class Printable
{
public:
	virtual void print() const = 0;
	virtual ~Printable() {}
};

class Named: virtual public Printable
{
public:
	Named( std::string const & name ): name( name ) {}
	std::string const & GetName() const { return name; }

private:
	std::string name;
};

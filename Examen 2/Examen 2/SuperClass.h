#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class SuperClass {
protected:

public:
	SuperClass();
	virtual ~SuperClass();

	virtual string toString() const;

};
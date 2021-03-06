/**********************************
*  test.cpp                       *
**********************************/
#include "test.h"
#include "colormod.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
Test::Test(string pname) : name(pname), passed(0) {
    using namespace Color;
    Modifier dim(DIM_SET), def(DIM_UNSET);
    cout << dim << "Testing " << name << "..." << def << endl;
}
Test::~Test() {
	cout << name << " passed " << passed << " tests.\n";
}

/**********************************
*  sample_test.cpp                *
**********************************/
#include "sample_test.h"
#include <cctype>
#include <cstring>
void strtolower(char c[8]) {
    for (int i = 0; i < 8; i++)
        c[i] = tolower(c[i]);
}
SampleTest::SampleTest() : Test("Sample") {
    EQ(1 + 1, 2);
    char sTR[] = "ABCdEFjd";
    char str[] = "abcdefjd";
    EQ(strcmp(sTR, str) != 0, true);
    strtolower(sTR);
    EQ(strcmp(sTR, str), 0);
}

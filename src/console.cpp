/**********************************
*  console.cpp                    *
**********************************/
#include "console.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include "colormod.h"
using std::string;
using std::cin;
using std::ostringstream;
Console::Console(const Args& pargs) : args(pargs) {}
void Console::f(string msg, ...) const {
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    if (true) {
	    fprintf(stderr, "%sE:%s ", str(red).c_str(), str(def).c_str());
	    va_list args;
	    va_start(args, msg);
	    vfprintf(stderr, msg.c_str(), args);
	    va_end(args);
	    fprintf(stderr, "\n");
	}
}
void Console::e(string msg, ...) const {
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
	if (show_e()) {
		fprintf(stderr, "%sE:%s ", str(red).c_str(), str(def).c_str());
		va_list args;
		va_start(args, msg);
		vfprintf(stderr, msg.c_str(), args);
		va_end(args);
		fprintf(stderr, "\n");
	}
}
void Console::w(string msg, ...) const {
    Color::Modifier yel(Color::FG_YELLOW);
    Color::Modifier def(Color::FG_DEFAULT);
	if (show_w()) {
		printf("%sW:%s ", str(yel).c_str(), str(def).c_str());
		va_list args;
		va_start(args, msg);
		vprintf(msg.c_str(), args);
		va_end(args);
		printf("\n");
	}
}
void Console::v(string msg, ...) const {
	if (show_v()) {
		va_list args;
		va_start(args, msg);
		vprintf(msg.c_str(), args);
		va_end(args);
		printf("\n");
	}
}
void Console::d(string msg, ...) const {
	if (show_d()) {
		va_list args;
		va_start(args, msg);
		vprintf(msg.c_str(), args);
		va_end(args);
		printf("\n");
	}
}
void Console::ui(string msg, ...) const {
	if (true) {
		va_list args;
		va_start(args, msg);
		vprintf(msg.c_str(), args);
		va_end(args);
	}
}
bool yn(bool def) {
    const char response = cin.get();
    const char nocase = tolower(response);
    if (nocase == '\n') return def;
    cin.ignore(1000, '\n');
    if (nocase == 'y') return true;
    if (nocase == 'n') return false;
    return false;
}
bool Console::Yn(string msg, ...) const {
	if (true) {
		va_list args;
		va_start(args, msg);
		vprintf(msg.c_str(), args);
		va_end(args);
	}
	return yn(true);
}
bool Console::yN(string msg, ...) const {
	if (true) {
		va_list args;
		va_start(args, msg);
		vprintf(msg.c_str(), args);
		va_end(args);
	}
	return yn(false);
}
bool Console::show_e() const { return ERROR <= args.verbosity; } 
bool Console::show_w() const { return WARNING <= args.verbosity; }
bool Console::show_v() const { return VERBOSE <= args.verbosity; }
bool Console::show_d() const { return DEBUG <= args.verbosity; }

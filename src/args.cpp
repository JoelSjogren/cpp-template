/**********************************
*  args.cpp                       *
**********************************/
#include "args.h"
#include "help.h"
#include "build_no.h"
#include "ostream_overloads.h"
#include "console.h"
#include <unistd.h>     // getopt - argument parsing
#include <getopt.h>     // also getopt
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <cstring>
#include <cerrno>
#include <set>
#include <sstream>
#include <cctype>
#include <cassert>
#include <cstdlib>
using std::ostream;
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::vector;
using std::istringstream;
using std::ostringstream;
using std::ios_base;
void help() {
	for (int i = 0; i < ___HELP_md_len; i++)
		cout << ___HELP_md[i];
	cout << endl;
}
void build_no() {
    for (int i = 0; i < build_no_txt_len; i++)
        cout << build_no_txt[i];
    cout << endl;
}
std::ostream& operator<<(std::ostream& os, const Args& args) {
	os << "Arguments:\n";
	#define ARGS_D(X) os << "  " #X ": " << args.X << endl
    os << std::boolalpha; // prettier output
	ARGS_D(verbosity);
	os << std::noboolalpha;
	#undef ARGS_D
	return os;
}
int Args::parseInt(string str) {
	int result;
	istringstream iss(optarg);
    iss >> result;
    if (iss.fail()) {
        Console console(*this);
		console.f("Unable to interpret integer: %s", str.c_str());
		exit(1);
	}
	return result;
}
Args::Args()
	: verbosity(0) {}
Args::Args(int argc, char* const* argv)
	: verbosity(0) {
	Console console(*this);
	static const struct option longopts[] = {
		{ "build-no",  	    no_argument,		NULL, 'b' },
		{ "help",	 	    no_argument,		NULL, 'h' },
		{ "verbosity", 	    required_argument,	NULL, 'v' },
		{ NULL,		    	0,					NULL,  0  },
	};
	static const char* shortopts = "bhv:";
	bool done = false;
	optind = 1;
	while (!done) {
		int index = -1;
		char c = getopt_long(argc, argv, shortopts, longopts, &index);
		switch (c) {
		case 'b':
		    build_no();
		    exit(0);
		case 'h':
			help();
			exit(0);
		case 'v':
			verbosity = parseInt(optarg);
			break;
		case -1:
			done = true;
			break;
		case '?':
			console.f("Got unexpected option: %s\n"
			          "Try `%s --help' for more information.",
			          argv[optind - 1], argv[0]); // FIXME safe?
			exit(1);
		case ':':
		    console.f("Missing option argument for: %s\n"
		              "Try `%s --help' for more information.",
		              argv[optind - 1], argv[0]);
		    exit(1);
		default:
			console.f("Failed to interpret command line "
			          "arguments. getopt returned %d", c);
			exit(1);
		}
	}
	if (console.show_d()) cout << *this;
}

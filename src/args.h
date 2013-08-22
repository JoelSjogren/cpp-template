/**********************************
*  args.h                         *
*                                 *
*  Parses and stores command      *
*  line arguments.                *
**********************************/
#pragma once
#include <string>
typedef long long clean_t;
class Args {
	int parseInt(std::string str);
public:
	int verbosity;
	Args();
	Args(int argc, char* const* argv);
};

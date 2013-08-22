/**************************
*  app - short descrip... *
*   by someone            *
**************************/
#include "args.h"
#include "console.h"
#include "colormod.h"
#include <string>
#include <cstdlib>
#include <ctime>
using std::string;
void printHello(Args& args);
int main(int argc, char* argv[]) {
	Args args(argc, argv);
    printHello(args);
}
void printHello(Args& args) {
	Console console(args);
	const string msg = "Hello, World!";
	using namespace Color;
	const Code colors[] = { FG_RED, FG_GREEN, FG_YELLOW, FG_BLUE };
	const int colorc = sizeof(colors) / sizeof(*colors);
    srand(time(NULL));
    for (int i = 0; i < msg.size(); i++) {
        Modifier mod(colors[rand() % colorc]);
        console.ui("%s%c", console.str(mod).c_str(), msg[i]);
    }
    Modifier mod(FG_DEFAULT);
    console.ui("%s\n", console.str(mod).c_str());
}

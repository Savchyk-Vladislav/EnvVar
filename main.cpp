#include <iostream>
#include <cstdlib>
#include <string>
#include "environ.h"
using namespace std;

int main(int argc, char* argv[]) {
    Environ environ;
    if (argc == 1) {
        environ.displayEnv();
    } else if (argc == 2 && (string(argv[1]) == "-h" || string(argv[1]) == "--help")) {
        environ.displayHelp();
    } else if (argc == 3 && (string(argv[1]) == "-i" || string(argv[1]) == "--info")) {
        environ.displayVarVal(argv[2]);
    } else if (argc == 3 && (string(argv[1]) == "-s" || string(argv[1]) == "--set")) {
        environ.setVarVal(argv[2]);
    } else if (argc == 5 && (string(argv[1]) == "-a" || string(argv[1]) == "--assign") &&
               (string(argv[3]) == "-v" || string(argv[3]) == "--value")) {
        environ.assignVarVal(argv[2], argv[4]);
    } else if (argc == 3 && (string(argv[1]) == "-d" || string(argv[1]) == "--del")) {
        environ.deleteVar(argv[2]);
    } else if (argc == 2 && (string(argv[1]) == "-c" || string(argv[1]) == "--clear")) {
        environ.clearEnv();
    } else {
        cerr << "Invalid arguments. Use -h or --help for usage instructions." << endl;
    }
    return 0;
}

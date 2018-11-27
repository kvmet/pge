//
// Created by kvmet on 11/25/2018.
//

//TODO: Move includes to headers...
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include "assets/input.h"
#include "assets/output.h"


/*TODO:
 * Going to just put some basic thoughts here until I get a good system going:
 * - GPL V3.0 License
 * - SQLite for any specific detail storage. Should build types in a way
 *      that makes them flexible and easily controllable using properties/tables
 *      stored in SQL...
 * - Try to use standard c/c++ libraries wherever possible
 * - In cases where system libraries/calls must be used, abstract them a bit into
 *      generalized functions that can be rewritten for each system, yet used
 *      exactly the same way.
 * - Use exceptions
 *
 *
 * tips on setting up execution path in clion:
 * application
 * target is whatever
 * executable is  powershell.exe
 * arguments is start powershell .\executableName.exe
 * working directory is the location of the executable
 */

using namespace pge;

int main() {
    try {
        string s,t;
        vector<string> e;
        cout << "Is anyone there?" << endl;
        s = getInput("interr");
        e = explode(s);

        while (!e.empty()) {
            t = e.front();
            e.erase(e.begin());
            cout << t;
        }
        cout << "!!";

        cin >> s;

    } catch(const std::exception& e) {
        // General Catch-All exception for everything ever...
        std::cout << "An exception occurred with message '" << e.what() << "'" << endl;
        return -1;
    }
    return 0;
}
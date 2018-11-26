//
// Created by kvmet on 11/25/2018.
//

#ifndef PGE_INPUT_H
#define PGE_INPUT_H

#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;

string getInput(string interruptKeyword = "") {
    string s;
    char t;

    do {
        t = (char) _getch(); // Get char

        // Sanitize
        if (13 == (int) t) continue;

        // Handle backspacing...
        if (8 == (int) t && s.length() > 0) {
            cout << "\b \b";
            if (!s.empty()) s.pop_back();
            continue;
        }

        cout << t; // Repeat back entered chars
        s += t; // Add new char to buffer

        // Handle interrupt
        if(string::npos != s.find(interruptKeyword,0)) {
            cout << "-";
            break;
        }
    } while ( 13 != (int) t ); // Exit on "Enter"
    cout << endl;
    return s;

    //todo: use vector of keywords for interrupts?
    //todo: sanitize
    //todo: also split output into a vector?
    //todo: if making vector splits then consider making an overload?
}


#endif //PGE_INPUT_H

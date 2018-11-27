//
// Created by kvmet on 11/25/2018.
//

#define ALLOWED_CHARS " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890~$%"

#ifndef PGE_INPUT_H
#define PGE_INPUT_H

#include <string>
#include <vector>
#include <iostream>

// Windows-specific
#include <conio.h>

namespace pge {
    using namespace std;

    //todo: look up doxygen formatting?

    //
    //  Retrieve a single char from the user *without echoing it back*
    //
    char getChar() { return (char) _getch(); }

    //
    //  Split words into vector<string>
    //
    vector<string> explode(string s) {
        vector<string> v;
        unsigned int p;

        while(!s.empty()) {
            p = s.find(' ');

            if (p != string::npos && p != 0) {
                v.push_back(s.substr(0, p));
                s.erase(0, p + 1);

            } else if(p == 0) {
                s.erase(s.begin());

            } else {
                v.push_back(s);
                break;
            }
        }
        return v;
    }

    //
    //  Retrieve a string from the user
    //  -   Echos back as the user types
    //  -   Filters allowed characters
    //  -   Completes immediately once a specified keyword is present in the string
    //
    string getInput(const string &interruptKeyword = "") {
        string s;
        string allow = ALLOWED_CHARS;
        char t;

        do {
            t = getChar();

            // Handle backspace
            if (8 == (int) t && s.length() > 0) {
                cout << "\b \b";
                if (!s.empty()) s.pop_back();
                continue;
            }

            // Jump to end if not a valid entry
            if (string::npos == allow.find(t)) continue;

            cout << t;
            s += t;

            // Handle interrupt
            if(string::npos != s.find(interruptKeyword,0)) {
                cout << "-";
                break;
            } //todo: should make sure that interrupt is its own word? what if phrase? what if multiple? vector?

        } while ( 13 != (int) t ); // Exit on "Enter"

        cout << endl;
        return s;
    }
}

#endif //PGE_INPUT_H

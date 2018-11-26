//
// Created by kvmet on 11/25/2018.
//

//TODO: Move includes to headers...
#include <string>
#include <vector>
#include <iostream>


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
 */

using namespace std;

int main() {
    try {
        cout << "Hello World..." << endl;


    } catch(const std::exception& e) {
        // General Catch-All exception for everything ever...
        std::cout << "An exception occurred with message '" << e.what() << "'" << endl;
        return -1;
    }
    return 0;
}
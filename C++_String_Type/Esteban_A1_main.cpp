/* File name: Esteban_A1_main.cpp
 * Javier Esteban de Celis
 * September 3rd 2018 
*/

#include <iostream>
#include <string.h>
#include "Esteban_A1.cpp"

using namespace std;


int main() {
    String s("this");
    String p("that");
    String t;
    String x = "hi";


    cout << "Please input a word: ";
    cin >> t;

    cout << endl << x << endl;
    cout << x[1] << endl;
    cout << x.length() << endl;

    cout << s << endl;
    cout << s.length() << endl;

    cout << t << endl;
    cout << t.length() << endl;

    cout << s[0] << endl;
    cout << s[1] << endl;

    s = "Hello hello";

    cout << s << endl;
    cout << s.length() << endl;

    s += " ";
    s += p;

    cout << s << endl;
    cout << s.length() << endl;

    s += " hello";

    cout << s << endl;
    cout << s.length() << endl;

    return 0;
}
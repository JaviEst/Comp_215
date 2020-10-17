/* File name: Esteban_A1.h
 * Javier Esteban de Celis
 * September 3rd 2018
 *
 * Description: This program implements some of the methods of a string class.
 *              The operators that can be used are:
 *                  - operator=
 *                  - operator+=
 *                  - operator>>
 *                  - operator<<
 *                  - operator[]
 *                  - length method
 *
 * Input:  The user can still use cin >>. The input will depend on the user.
 * Output: The user can still use cout <<. The output will depend on the user.
 */

#include <string.h>
#include <iostream>

using namespace std;


class String
{
public:
    String();                       // CTOR
    String(char* newString);        // CTOR

    ~String();                      // DTOR

    long length() const;            // Method to get the length

    char& operator[](/*in*/ short i) const;                                     // Method to set the elements of a string

    friend istream& operator>>(/*inout*/istream& input, /*in*/ String& s);      // Cin operator
    friend ostream& operator<<(/*inout*/ostream& output, /*in*/ String& s);     // Cout operator

    String& operator=(/*in*/char * s);                              // = operator
    String& operator+=(/*inout*/ const String& s);             // += operator for String
    String& operator+=(/*inout*/ char * s);                         // += operator for char*


private:
    long size;          // size of the buffer
    char * buffer;      // array of char to store the string
};
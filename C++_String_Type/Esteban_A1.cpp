/* File name: Esteban_A1.cpp
 * Javier Esteban de Celis
 * September 3rd 2018 
*/

#include <string.h>
#include "Esteban_A1.h"

//-----------------------------------------------------------------------
//----- Constructors (CTOR) ---------------------------------------------

String::String()
/*
PRE:  None
POST: Will create a new string object with the default settings
*/
{
    this->size = 0;                             // Default size
    this->buffer = new char[NULL];              // Creates a null string
}

//-----------------------------------------------------------------------

String::String(/*in*/char* newString)
/*
PRE:  newString is assigned
POST: Will create a new string object
*/
{
    long l;
    l = strlen(newString);

    this->size = l;                             // Size assigned
    this->buffer = new char[l+1];               // Creates a new string

    strcpy(buffer, newString);

}


//----- Destructor (DTOR) -----------------------------------------------

String::~String()
/*
PRE:  None
POST: Will free buffer so that memory can be used again
*/
{
    delete [] buffer;           // cleans the space we were using in the Heap
}


//----- Get Length of String -----------------------------------------------

long String::length() const
/*
PRE:  None
POST: return the length of the buffer
 */
{
    long length;
    length = this->size;

    return (length);
}


//----- Set elements of String -----------------------------------------------

char & String::operator[](/*in*/ short i) const
/*
PRE:  i is assigned
POST: Returns desired dereferenced string element
*/
{
    // Checks that i is a valid index, if not the program exits
    if (i < 0 || i >= this->size)
    {
        cerr << "ERROR:index [" << i << "] is out of bounds." << endl;
        system("PAUSE");
        exit(-1);
    }// end if

    return buffer[i];
}


//----- Read String -----------------------------------------------

istream& operator>>(/*inout*/istream& input, /*in*/ String& s)
/*
PRE:  >> operators still used with cin
POST: Returns istream input for the string
*/
{
    char * c = new char [5];
    char * temp;

    long len = 5;
    long l = 0;

    c[l] = input.get();

    while (c[l] != '\n')
    {
        if (l >= len)
        {
            len = 2*len;

            temp = c;

            c = new char[len + 1];
            strcpy(c, temp);

            delete [] temp;

        }
        l++;

        c[l] = input.get();
    }

    s.size = l;
    s.buffer = new char[l + 1];

    strcpy(s.buffer, c);

    return input;
}


//----- Print String -----------------------------------------------

ostream& operator<<(/*inout*/ostream& output, /*in*/ String& s)
/*
PRE:  << operators still used with cout
POST: Returns ostream output for the string
*/
{
    if (s.length() > 0)
    {
        for (short i = 0; i < s.length(); i++)
        {
            output << s[i];
        }
    }
    else
    {
        output << "";
    }

    return output;
}


//----- Operator = -----------------------------------------------

String& String::operator=(char * s)
/*
PRE:  s is assigned
POST: returns a String object with the new values from s in it. Also updates the size of it.
 */
{
    long l = strlen(s);

    this->size = l;
    this->buffer = new char[l + 1];

    strcpy(buffer, s);

    return *this;
}


//----- Operator += -----------------------------------------------

String& String::operator+=(const String &s)
/*
PRE:  s is assigned
POST: returns a String object updated. You will have the old 'string' + the new 'string'
      Also updates the size of it.
 */
{
    char * temp = new char[this->size];
    strcpy(temp, buffer);

    long l = this->size + s.size;

    this->size = l;
    this->buffer = new char[l + 1];

    strcpy(buffer, temp);
    strcat(buffer, s.buffer);

    delete [] temp;

    return *this;
}


//----- Operator += -----------------------------------------------
String& String::operator+=(char *s)
/*
PRE:  s is assigned
POST: returns a String object updated. You will have the old 'string' + the new 'string'
      Also updates the size of it.
 */
{
    char * temp = new char[this->size];
    strcpy(temp, buffer);

    long l = strlen(s);
    l = l + this->size;

    this->size = l;
    this->buffer = new char[l + 1];

    strcpy(buffer, temp);
    strcat(buffer, s);

    delete [] temp;

    return *this;
}
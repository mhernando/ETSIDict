 

ETSIDICT - STATIC LIB
=====================

Static library that embeds the Spanish dictionary.

It is a wrapper around "**MySpell**" which avoids having to load the dictionary
files at running time. Instantiate the object “Spanish” and use two simple
methods to check if a word belongs to Spanish dictionary or not.

A precompiled debug binary lib (VS2012) has been included into the lib
directory, to easily start using its functionality.

 

The lib has been created to be used by students at **UPM** (Madrid-Spain), so
they can easily try to create algorithms for decoding messages through the
frequency method.

The code would be as simple as:

 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "lib/ETSIDICT.h"
...
void main()
{
  const char example1[]=”hola”, example2[]=”xysholajdksk”;
  Spanish diccionario;
  if(diccionario.check(”example1”){ //check a complete word.
    ...
  }
  if(diccionario.check(example2+3,4)){ //check a substring.
    ...
  }
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 

There are four check methods:

-   **bool check(const char \*word);**

    UTF-8 const char \*word (null terminated). true if the word is found at the
    dictionary

-   **bool check(const char \*init, int n);**

    UTF-8 const char \*substring. true if a substring of n chars belongs to the
    dictionary

    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       diccionario.check(”Holaamigo”,4) would be true, false for any other number
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

-   **bool check(const string \&word);**

    UTF-8 std::string. true if the word is Spanish

-   **bool check(const string &line, int ini, int num);**

UTF-8 std::string subtring that begin at the character in position ini and has a
num lenght

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
string mystring(”Holaamigo”);
diccionario.check(mystring,4,5) //true (substring “Hola”)        diccionario.check(mystring,0,4) //true (substring “amigo”)   diccionario.check(mystring,4,1) //true (substring “a”)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

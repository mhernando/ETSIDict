 

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

 

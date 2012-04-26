/*
    Copyright (c) 2012 Torbjörn Klatt <opensource@torbjoern-klatt.de>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/


#include "../headers/koan02_character_types.hpp"

#include <string>

void Koan02_character_types::lonely_characters()
{
  char a_character = 'a';
  ASSERT_EQUAL( a_character, FILL_THE_CHAR_IN );
}

void Koan02_character_types::chars_have_a_size()
{
  char a_character = 'a';
  ASSERT_EQUAL( sizeof( char ), FILL_THE_NUMBER_IN );
  ASSERT_EQUAL( sizeof( a_character ), FILL_THE_NUMBER_IN );
}

void Koan02_character_types::chars_are_numbers()
{
  char a_character = 'a';
  ASSERT_EQUAL( int( a_character ), FILL_THE_NUMBER_IN );
  unsigned char the_same_charater = 'a';
  ASSERT_EQUAL( int( the_same_charater ), FILL_THE_NUMBER_IN );
  signed char still_the_same_character = 'a';
  ASSERT_EQUAL( int( still_the_same_character ), FILL_THE_NUMBER_IN );
}

void Koan02_character_types::more_characters_are_strings()
{
  std::string some_characters = "Hello World";
  ASSERT_EQUAL( some_characters.length(), FILL_THE_NUMBER_IN );
  ASSERT_EQUAL( some_characters.size(), FILL_THE_NUMBER_IN );
}

// EOF

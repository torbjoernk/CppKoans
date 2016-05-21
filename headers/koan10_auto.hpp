/*
    Copyright (c) 2016 Thibauld Nion <tibonihoo@yahoo.fr>

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

#include "../helper.hpp"

// Do not to forget to rename the preprocessor directives as well!
#ifndef KOAN10_AUTO_HPP
#define KOAN10_AUTO_HPP

// Rename the Episode
class Koan10_auto : Koan
{
  private:
    KoanHandler *status;                //!
    // When ever a koan is added at the very bottom, this counter needs to be
    // increased.
    static const int num_tests = 9;     //!

  public:
    /**
     *
     */
    Koan10_auto( KoanHandler *status ) : status( status ) {
      status->register_koans( num_tests );
    }
    /**
     *
     */
    ~Koan10_auto() {}

    /**
     *
     */
    void run() {
	
      status->episode_start( "auto" );
	  
      // For each koan in this episode, one line needs to be written.
      // The koans are executed in the order they are called here.
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan10_auto::use_decltype_to_get_an_expression_type) );
  	  status->eval_koan(*this, static_cast<void (Koan:: *)()>(&Koan10_auto::static_cast_is_how_you_force_a_variable_type));
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan10_auto::auto_ignores_constness) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan10_auto::auto_ignores_referenceness) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan10_auto::auto_with_universal_reference_distinguishes_lvalue_and_rvalue) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan10_auto::auto_decays_arrays_and_functions) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan10_auto::auto_assumes_braces_are_initializer_list) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan10_auto::decltype_auto_use_decltype_type_deduction_rules) );

      status->episode_done( "auto" );
    }

    /**
     *
     */
    static int get_num_tests() {
      return num_tests;
    }

  private:
    // Add further Koans down here by defining their name.
    // The implementation of these is done in ~/koans/koan10_auto.cpp
    // REMARK: Do not forget to increase this.num_tests when you add
    // another koan
	
	void use_decltype_to_get_an_expression_type();

	void static_cast_is_how_you_force_a_variable_type();

	void auto_ignores_constness();

	void auto_ignores_referenceness();
	
    void auto_with_universal_reference_distinguishes_lvalue_and_rvalue();
	
	void auto_decays_arrays_and_functions();
	
	void auto_assumes_braces_are_initializer_list();

	void decltype_auto_use_decltype_type_deduction_rules();
};


	
#endif // KOAN10_AUTO_HPP

// EOF

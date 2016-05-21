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
#ifndef KOAN11_LAMBDAS_HPP
#define KOAN11_LAMBDAS_HPP

// Rename the Episode
class Koan11_lambdas : Koan
{
  private:
    KoanHandler *status;                //!
    // When ever a koan is added at the very bottom, this counter needs to be
    // increased.
    static const int num_tests = 8;     //!

  public:
    /**
     *
     */
    Koan11_lambdas( KoanHandler *status ) : status( status ) {
      status->register_koans( num_tests );
    }
    /**
     *
     */
    ~Koan11_lambdas() {}

    /**
     *
     */
    void run() {
	
      status->episode_start( "lambdas" );
	  
      // For each koan in this episode, one line needs to be written.
      // The koans are executed in the order they are called here.
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::bracket_paren_mustache_makes_a_lambda) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::lambdas_make_generic_algorithms_easier_to_user) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::lambdas_can_capture_their_creation_context_in_a_closure) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::lambdas_can_capture_references_to_their_creation_context) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::lambdas_can_modify_their_creation_context) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::stay_away_from_default_capture_mode_reference) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::stay_away_from_default_capture_mode_copy) );
      status->eval_koan( *this, static_cast<void ( Koan:: * )()>( &Koan11_lambdas::lambdas_can_help_with_your_curry_ing) );

      status->episode_done( "lambdas" );
    }

    /**
     *
     */
    static int get_num_tests() {
      return num_tests;
    }

  private:
    // Add further Koans down here by defining their name.
    // The implementation of these is done in ~/koans/koan11_lambdas.cpp
    // REMARK: Do not forget to increase this.num_tests when you add
    // another koan
	
	void bracket_paren_mustache_makes_a_lambda();
	
	void lambdas_make_generic_algorithms_easier_to_user();

	void lambdas_can_capture_their_creation_context_in_a_closure();
	
	void lambdas_can_capture_references_to_their_creation_context();
	
	void lambdas_can_modify_their_creation_context();

	void stay_away_from_default_capture_mode_reference();

	void stay_away_from_default_capture_mode_copy();
	
	void lambdas_can_help_with_your_curry_ing();
	
};

#define REPLACE_WITH_CORRECT_LAMBDA []() { return 0; }

#define REPLACE_WITH_CORRECT_LAMBDA_I0 [](int i) { return 0; }

	
#endif // KOAN11_LAMBDAS_HPP

// EOF

/*
    Copyright (c) 2015 Thibauld Nion <thibauld@tibonihoo.net>

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

#include "../headers/koan11_lambdas.hpp"
#include <vector>
#include <algorithm>
#include <functional>

// The implementations of the different koans of this episode is done here.
// Don't forget to rename the above include.

void Koan11_lambdas::bracket_paren_mustache_makes_a_lambda()
{
	auto lambda = REPLACE_WITH_CORRECT_LAMBDA;
	ASSERT_EQUAL( 42, lambda() );
}

void Koan11_lambdas::lambdas_make_generic_algorithms_easier_to_user()
{
	const std::vector<int> values = { 1, 41, 7, 13, 84, 9};

	{
		// Without lambdas
		struct Is42Divisible
		{
			bool operator()(const int &arg) const { return arg%42 == 0; }
		};
		auto it = std::find_if(values.begin(), values.end(), Is42Divisible());
		ASSERT(values.end() != it);
		ASSERT_EQUAL(84, *it);
	}
	
	{
		// With lambdas
		auto it = std::find_if(values.begin(), values.end(), REPLACE_WITH_CORRECT_LAMBDA_I0);
		ASSERT(values.end() != it);
		ASSERT_EQUAL(84, *it);
	}
}

void Koan11_lambdas::lambdas_can_capture_their_creation_context_in_a_closure()
{
	const std::vector<int> values = { 0, 1, 1, 0, 0, 1, 0, 0};
	
	const int countZeroesOrOnes = FILL_THE_NUMBER_IN;
	
	auto lambda = [countZeroesOrOnes](int i){ return i==countZeroesOrOnes; };
	
	ASSERT_EQUAL(3, std::count_if(values.begin(), values.end(), lambda ));
}

void Koan11_lambdas::lambdas_can_capture_references_to_their_creation_context()
{
	const std::vector<int> values = { 0, 1, 1, 0, 0, 1, 0, 0};
	
	int countZeroesOrOnes = FILL_THE_NUMBER_IN;

	auto lambda = [&countZeroesOrOnes](int i){ return i==countZeroesOrOnes; };
	
	countZeroesOrOnes = (countZeroesOrOnes+1)%2;
	
	ASSERT_EQUAL(5, std::count_if(values.begin(), values.end(), lambda ));
}

void Koan11_lambdas::lambdas_can_modify_their_creation_context()
{
	const std::vector<int> values = { 0, 1, 23, 41, 84, 1, 7, 98};
	
	int someOddNumberCount = 0;
	int someEvenNumberCount = 0;
	
	auto lambda = [&someOddNumberCount, &someEvenNumberCount](int i){
		if (i%2) someOddNumberCount = i; else someEvenNumberCount = i;
	};
	
	std::for_each(values.begin(), values.end(), lambda);
	
	ASSERT_EQUAL(FILL_THE_NUMBER_IN, someOddNumberCount);
	ASSERT_EQUAL(FILL_THE_NUMBER_IN, someEvenNumberCount);
}

// inspired by Effective Modern C++ Item 31 - Scott Meyers
void Koan11_lambdas::stay_away_from_default_capture_mode_reference()
{
	// Find where to correct this code
	for(int i=0; i<100; ++i)
	{
		const std::vector<int> values = { 42, 1, 75, 2, 3, 77 };
		
		auto lambdaFactory = [](int targetIndex)
			{
				std::vector<int> targets = { 1, 2, 3 };
				return [&](int i) { return i == targets[targetIndex];};
			};
		auto lambda = lambdaFactory(2);
		
		auto it = std::find_if(values.begin(), values.end(), lambda);
		ASSERT_EQUAL(4, std::distance(values.begin(), it));
	}
}


// inspired by Effective Modern C++ Item 31 - Scott Meyers
void Koan11_lambdas::stay_away_from_default_capture_mode_copy()
{
	// Find where to correct this code
	
	const std::vector<int> values = { 0, 1, 23, 1, 84, 1, 7, 98};
	
	struct ZeroOrOnePredicateProvider
	{
		int selectZeroOrOne;
		
		ZeroOrOnePredicateProvider(int zeroOrOne)
			: selectZeroOrOne(zeroOrOne)
		{}
		
		std::function<bool(int)> CreatePredicate()
		{
			return [=](int i){ return i == selectZeroOrOne; };
		}
	};
	

	ZeroOrOnePredicateProvider provider(0);
	auto zeroPredicate = provider.CreatePredicate();
	provider.selectZeroOrOne = 1;
	auto onePredicate = provider.CreatePredicate();	
	
	auto itZeroes = std::find_if(values.begin(), values.end(), zeroPredicate);
	auto itOnes   = std::find_if(values.begin(), values.end(), onePredicate);
	
	ASSERT(std::distance(itOnes, itZeroes) != 0);
}

// Currying: partial application of a function (see https://en.wikipedia.org/wiki/Currying)
// also inspired by Effective Modern C++ Item 34 - Scott Meyers
void Koan11_lambdas::lambdas_can_help_with_your_curry_ing()
{
	// 3-ary function
	auto threeAryFunction = [](int a, int b, int c){ return a*b + c; };

	auto bind3rd = [](int k, std::function<int(int, int, int)> f)
		{
			return [=](int a, int b){ return f(a, b, k); };
		};
	
	auto bind2nd = [](int k, std::function<int(int, int)> f)
		{
			return [=](int a){ return f(a, k); };
		};

	// Use the binds to create the correct function
	auto straightLineFunc = REPLACE_WITH_CORRECT_LAMBDA_I0;
	
	ASSERT_EQUAL(33, straightLineFunc(0));
	ASSERT_EQUAL(42, straightLineFunc(1));	
}


// EOF

/*
	Nathan Yarrison
	CISP 430
	9/20/2017
	Assignment 2: Sequence 2 project
*/
// This is the implementation program will create a dynamically allocated sequence of numbers that can grow and shrink in size.

#include "sequence2.h"
#include <cstdlib>

using namespace std;

namespace CISP430_A2
{
	CISP430_A2::sequence::sequence(size_type entry)
	{
	}

	CISP430_A2::sequence::sequence(const sequence & entry)
	{
	}

	void CISP430_A2::sequence::start()
	{
	}

	void CISP430_A2::sequence::advance()
	{
	}

	void CISP430_A2::sequence::insert(const value_type & entry)
	{
	}

	void CISP430_A2::sequence::attach(const value_type & entry)
	{
	}

	void CISP430_A2::sequence::remove_current()
	{
	}

	void CISP430_A2::sequence::resize(size_type)
	{
	}

	void CISP430_A2::sequence::operator=(const sequence &)
	{
	}

	size_type CISP430_A2::sequence::size() const
	{
		return size_type();
	}

	bool CISP430_A2::sequence::is_item() const
	{
		return false;
	}

	value_type CISP430_A2::sequence::current() const
	{
		return value_type();
	}

	CISP430_A2::sequence::~sequence()
	{
	}
}
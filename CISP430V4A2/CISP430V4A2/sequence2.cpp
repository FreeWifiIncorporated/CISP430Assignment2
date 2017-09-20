// Christos Papadopoulos
// sequence2.cpp
//	Implementation file for sequence2.h

#include <cstdlib>  // Provides size_t
#include "sequence2.h"

using namespace std;

namespace CISP430_A2
{
	sequence::sequence(size_type entry)
	{
	}
	sequence::sequence(const sequence & entry)
	{
	}
	void sequence::start()
	{
	}
	void sequence::advance()
	{
	}
	void sequence::insert(const value_type & entry)
	{
	}
	void sequence::attach(const value_type & entry)
	{
	}
	void sequence::remove_current()
	{
	}
	void sequence::resize(size_type)
	{
	}
	void sequence::operator=(const sequence &)
	{
	}
	size_type sequence::size() const
	{
		return size_type();
	}
	bool sequence::is_item() const
	{
		return false;
	}
	value_type sequence::current() const
	{
		return value_type();
	}
	sequence::~sequence()
	{
	}
}
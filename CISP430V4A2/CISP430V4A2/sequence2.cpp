// Christos Papadopoulos
// Assignment 2
// sequence2.cpp
//	Implementation file for sequence2.h

#include <cstdlib>  // Provides size_t
#include "sequence2.h"

using namespace std;

namespace CISP430_A2
{
	sequence::sequence(size_type entry)
		: capacity(entry), used(0), current_index(0)
	{
		// allocate a dynamic array on the heap
		data = new value_type[capacity];
	}
	sequence::sequence(const sequence & entry)
		: capacity(entry.capacity), used(entry.used), current_index(0)
	{
		data = new value_type[capacity];
		
		for (int index = 0; index < entry.used; ++index)
		{
			data[index] = entry.data[index];
		}
	}
	void sequence::start()
	{
		current_index = 0;
	}
	void sequence::advance()
	{
		current_index++;
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
	size_t sequence::size() const
	{
		return size_type();
	}
	bool sequence::is_item() const
	{
		return (current_index <= used);
	}
	double sequence::current() const
	{
		return value_type();
	}
	sequence::~sequence()
	{
		delete[] data;
	}
}
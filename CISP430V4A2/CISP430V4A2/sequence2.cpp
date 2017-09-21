// Lorin Zhang
// sequence.cpp is the implementation file for sequence.h

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
		current_index = 0; // make the index back to zero to start at the beginning 
	}
	void sequence::advance()
	{
		current_index++; // advance index up one 
	}
	void sequence::insert(const value_type & entry)
	{
	}
	void sequence::attach(const value_type & entry)
	{
	}
	void sequence::remove_current() // removes the current item, and the item after this (if valid) is the new current item
	{
		current_index = 
	}
	void sequence::resize(size_type)
	{
	}
	void sequence::operator=(const sequence &)
	{
	}
	size_t sequence::size() const
	{
		return size_type(); // return the number of items in the sequence 
	}
	bool sequence::is_item() const // return true if there is a current item in the current index, return flase if nothing
	{
		if ()
		{
			return true;
		}
		else if ()
		{ 
				return false;
		}

	}
	double sequence::current() const 
	{
		return value_type(); // return the current item in the sequence 
	}
	sequence::~sequence()
	{
		delete[] data;
	}
}
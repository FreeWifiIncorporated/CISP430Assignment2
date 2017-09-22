// Christos Papadopoulos
// Assignment 2
// sequence2.cpp
//	Implementation file for sequence2.h

#include <cstdlib>  // Provides size_t
#include "sequence2.h"

using namespace std;

namespace CISP430_A2
{
	// 
	sequence::sequence(size_type entry)
		: capacity(entry), used(0), current_index(0)
	{
		// allocate a dynamic array on the heap
		data = new value_type[capacity];
	}

	// 
	sequence::sequence(const sequence & entry)
		: capacity(entry.capacity), used(entry.used), current_index(0)
	{
		data = new value_type[capacity];
		
		for (int index = 0; index < entry.used; ++index)
		{
			data[index] = entry.data[index];
		}
	}

	// 
	void sequence::start()
	{
		current_index = 0;
	}

	// 
	void sequence::advance()
	{
		current_index++;
	}

	// 
	void sequence::insert(const value_type & entry)
	{
		// If 
		if (size() >= capacity)
		{
			resize(capacity * 1.1);
		}

		// If 
		if (!is_item())
		{
			current_index = 0;
		}

		// Shift all items from the current element to the end of the sequence
		for (int i = size(); data[i] >= current_index; --i)
		{
			data[i] = data[i - 1];
		}

		// Insert the item into the current free element
		data[current_index] = entry;

		// Added an item to the list so used will increase by 1
		++used;
	}

	// 
	void sequence::attach(const value_type & entry)
	{
		if (size() >= capacity)
		{
			resize(capacity * 1.1);
		}


	}

	// 
	void sequence::remove_current()
	{

	}

	// 
	void sequence::resize(size_type newSize)
	{
		if (capacity > newSize)
		{
			capacity = newSize;

			value_type* tempData = new value_type[capacity];

			for (int index = 0; index < size(); ++index)
			{
				tempData[index] = data[index];
			}

			delete data;

			data = tempData;
		}
	}

	// 
	void sequence::operator=(const sequence & otherSequence)
	{
		
	}

	// 
	size_t sequence::size() const
	{
		return used;
	}

	// 
	bool sequence::is_item() const
	{
		// check if the current item is within the range of inserted items		
		return (current_index <= used);
	}

	// 
	double sequence::current() const
	{
		// Returns the current item in the sequence
		return data[current_index];
	}

	// 
	sequence::~sequence()
	{
		delete[] data;
	}
}
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
		
		for (size_type index = 0; index < entry.used; ++index)
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
		for (size_type i = size(); data[i] >= current_index; --i)
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
		if (size() > capacity) // 
		{
			resize(size_t(capacity * 1.1); // if so increase the capacity by 10%
		}

		if (is_item())
		{
			current_index++; // to insert after current item
			for (size_type i = used; data[i] > current_index; --i)
			{
				data[i] = data[i - 1]; // insert new copy
			}
		}
		else
		{
			// if no current item, new entry is now at front
		}

		data[current_index] = entry; // new item is now the current item
	}

	// 
	void sequence::remove_current()
	{
		//Removes the current item from the index.
		for (int i = current_index + 1; i < used; i++)
		{
			data[i - 1] = data[i]; //Takes an item in the sequence and moves it to the element before, removing the current item by shifting every item after over to the left
		}

		--used; //Decrements used by 1 because there is now one less item in the sequence.
	}

	// 
	void sequence::resize(size_type newSize)
	{
		if (capacity > newSize)
		{
			capacity = newSize;

			value_type* tempData = new value_type[capacity];

			for (size_type index = 0; index < size(); ++index)
			{
				tempData[index] = data[index];
			}

			delete[] data;

			data = tempData;
		}
	}

	// 
	void sequence::operator=(const sequence & otherSequence)
	{
		capacity = otherSequence.capacity;
		used = otherSequence.used;
		current_index = 0; // MIGHT CAUSE A PROBLEM IF IT NEEDS TO BE THE SAME INDEX AS THE PREVIOUS FOR THE EXAM

		delete[] data;

		data = new value_type[capacity];

		for (size_type index = 0; index < otherSequence.used; ++index)
		{
			data[index] = otherSequence.data[index];
		}
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
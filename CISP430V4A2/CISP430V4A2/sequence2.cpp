// Christos Papadopoulos
// Assignment 2
// sequence2.cpp
//	Implementation file for sequence2.h

#include <cstdlib>  // Provides size_t
#include "sequence2.h"

using namespace std;

namespace CISP430_A2 // BREAKPOINT DUE TO DESTRUCTORS, PROCEED WITH CAUTION, Might have to do with how the memory is being allocated tho.
{
	// Constructor that takes the initial capacity
	sequence::sequence(size_type entry)
		: capacity(entry), used(0), current_index(0)
	{
		// allocate a dynamic array on the heap
		data = new value_type[capacity];
	}

	// copy constructor that properly handles dynamically allocated memory
	sequence::sequence(const sequence & entry)
		: capacity(entry.capacity), used(entry.used), current_index(entry.current_index)
	{
		data = new value_type[capacity];
		
		for (size_type index = 0; index < entry.used; ++index) // OFF BY ONE!?
		{
			data[index] = entry.data[index];
		}
	}

	// sets the curren_index to the beginning of the list
	void sequence::start()
	{
		current_index = 0;
	}

	// advanced the current_index to the next element in data
	void sequence::advance()
	{
		current_index++;
	}

	// inserts a new value at the current location after shifting all elements after it to the right, or if the current index is not pointing to an item then it inserts the new value at the beginning
	void sequence::insert(const value_type & entry)
	{
		// If the amount of items used is larger than the capacity then it calls the resize function to increase capacity by 10%
		if (size() >= capacity)
		{
			resize(capacity * 1.1);
		}

		// Checks if the index is pointing to a used item in the array, and if not then sets the index to the beginning of the array
		if (!is_item())
		{
			current_index = 0;
		}

		// Shift all items to the right from the current element to the end of the sequence
		for (size_type i = size(); i > current_index; --i)
		{
			data[i] = data[i - 1];
		}

		// Adding an item to the list so used will increase by 1
		++used;

		// Insert the item into the current free element
		data[current_index] = entry;
	}

	// attaches a new value at the location after the current one after shifting all elements after the current location to the right, or if the current index is not pointing to an item then it attaches the new value to the end
	void sequence::attach(const value_type & entry)
	{
		if (size() > capacity) // If the amount of items used is larger than the capacity then it calls the resize function to increase capacity by 10%
		{
			resize(size_type(capacity * 1.1)); // if so increase the capacity by 10%
		}

		if (!is_item()) // Checks if the index is pointing to an element in the array, and if not points past the end of the used elements
		{
			current_index = size();
		}
		else // if it is pointing at an element then it will increase the index to point at the spot directly after it
		{
			current_index++; // to insert after current item
		}

		// shift all the elements to the right by one
		for (size_type i = size(); i > current_index; --i)
		{
			data[i] = data[i - 1]; // insert new copy
		}

		// Adding an item to the list so used will increase by 1
		++used;

		data[current_index] = entry; // new item is now the current item
	}

	// removes the item at the current location and shifts everything to the left
	void sequence::remove_current()
	{
		//Removes the current item from the index.
		for (size_type i = current_index + 1; i < used; i++)
		{
			data[i - 1] = data[i]; //Takes an item in the sequence and moves it to the element before, removing the current item by shifting every item after over to the left
		}

		--used; //Decrements used by 1 because there is now one less item in the sequence.
	}

	// creates a new dynamic array with the increased size, copies the old data to the new one, and releases the old allocated memory
	void sequence::resize(size_type newSize)
	{
		if (newSize > used) // check the precondition that the new size is greater than the currently used
		{
			capacity = newSize; // sets the capacity to be the new size

			value_type* tempData = new value_type[capacity]; // create a dynamic array and point to it with a temporary pointer

			for (size_type index = 0; index < size(); ++index) // copy the elements of the old dynamic array to the new one
			{
				tempData[index] = data[index];
			}

			data = tempData; // point the data pointer to the new array
		}
	}

	// assignment operator that ensures the dynamic array is copied properly
	void sequence::operator=(const sequence & otherSequence)
	{
		resize(otherSequence.capacity); // resize data to ensure it is at least as large as the other sequence
		used = otherSequence.used; // copy the used data member
		current_index = otherSequence.current_index; // copy the current index

		// copy the elements of the other sequence to the current one
		for (size_type index = 0; index < used; ++index)
		{
			data[index] = otherSequence.data[index];
		}
	}

	// return the count of used elements
	size_t sequence::size() const
	{
		return used;
	}

	// check if the current index is pointing at a proper item
	bool sequence::is_item() const
	{
		// check if the current item is within the range of inserted items		
		return (current_index < size());
	}

	// return the current item
	double sequence::current() const
	{
		// Returns the current item in the sequence
		return data[current_index];
	}

	// dynamic memory safe destructor
	sequence::~sequence()
	{
		delete[] data; // delete the dynamic array in the heap that data is pointing to
	}
}
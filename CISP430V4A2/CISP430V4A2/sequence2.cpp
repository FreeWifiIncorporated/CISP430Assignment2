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
		//Adds a new item to the front of the sequence.

		//Check if in the right spot to add a new item.
		size_type i; //Will be used to check against current_index to see if in the right.

					 //Check if size is greater than capacity. If it is, then increase the capacity by 10%
		if (size() > CAPACITY)
		{
			capacity += CAPACITY * .10; //Increases the capacity of the sequence by 10% of CAPACITY.
										//TBH, not even sure why this is needed.
		}

		if (!is_item())
		{
			//This checks if there is an item and if there isn't. sets current_index to 0 so that the new item is added at the front of the sequence.
			current_index = 0;
		}

		//Shift original items to the right one to make room for the new item.
		for (i = used; data[i] > 0; --i)
		{
			data[i] = data[i - 1];
		}

		//Add new entry to the front of the sequence (data[0]).
		data[0] = entry;

		//Add 1 to used to keep track of the size of the sequence.
		++used;
	}
	void sequence::attach(const value_type & entry)
	{
		if (size() > CAPACITY) // 
		{
			resize(size_t(capacity += CAPACITY * .10); // if so increase the capacity by 10%
		}

		if (is_item())
		{
			current_index++ // to insert after current item
			for (i = used; data[i] > current_index; --i)
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
	void sequence::remove_current() // removes the current item, and the item after this (if valid) is the new current item
	{
		//Removes the current item from the index.
		for (int i = current_index + 1; i < used; i++)
		{
			data[i - 1] = data[i]; //Takes an item in the sequence and moves it to the element before, removing the current item by shifting every item after over to the left
		}

		used--; //Decrements used by 1 because there is now one less item in the sequence.

				//Check if reset of capacity is needed.
		if ((used <= CAPACITY))
		{
			//If the size of the sequence is less than the CAPACITY, reset the sequences capacity.
			//This clears up some memory. Not much, but it's still some memory freed up
			capacity = CAPACITY;
		}
	}
	void sequence::resize(size_type)
	{
	}
	void sequence::operator=(const sequence &)
	{
	}
	size_t sequence::size() const
	{
		return used; // return the number of items in the sequence 
	}
	bool sequence::is_item() const // return true if there is a current item in the current index, return flase if nothing
	{
		return (current_index <= used);
	}
	double sequence::current() const 
	{
		//Calls is_item() to check if the current item is an appropriate item in the sequence.
		bool isItemGood = true;
		isItemGood = is_item();

		//If isItemGood is true, return the value of the current item to call.
		if (isItemGood == true)
		{
			return data[current_index];
		}
	}
	sequence::~sequence()
	{
		delete[] data;
	}
}
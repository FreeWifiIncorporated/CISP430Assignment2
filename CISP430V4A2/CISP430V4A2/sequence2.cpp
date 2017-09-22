/*
	Nathan Yarrison
	CISP 430
	9/20/2017
	Assignment 2: Sequence 2 project
*/
// This is the implementation program will create a dynamically allocated sequence of numbers that can grow and shrink in size.

#include "sequence2.h"
#include <cstdlib>
#include <cassert>

namespace CISP430_A2
{
	CISP430_A2::sequence::sequence(size_type entry)
		: capacity(entry), used(0), current_index(0) //Initialize values for constructor.
	{
		//Allocate a chunk of memory on the heap
		data = new value_type[capacity];
	}

	CISP430_A2::sequence::sequence(const sequence & entry)
		: capacity(entry.capacity), used(entry.used), current_index(0) //Initialize values for copy-constructor.
	{
		data = new value_type[capacity];

		for (int index = 0; index < entry.used; index++)
		{
			data[index] = entry.data[index];
		}
	}

	void CISP430_A2::sequence::start()
	{
		//Make the first item of the sequence the current item.
		//But if the sequence is empty, then there is no current item.
		
		//If there is something in the sequence, get the first value in the sequence using current().
		current_index = 0; //Resets the index back to 0 so the program is at the beginning of the sequence.
	}

	void CISP430_A2::sequence::advance()
	{
		//When called, increase the current_index by 1 to move to the next element in the sequence.
		current_index++; //Adds 1 to current value of current_index.
	}

	void CISP430_A2::sequence::insert(const value_type & entry)
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
		for ( i = used; data[i] > 0; --i)
		{
			data[i] = data[i - 1];
		}

		//Add new entry to the front of the sequence (data[0]).
		data[0] = entry;

		//Add 1 to used to keep track of the size of the sequence.
		++used;
	}

	void CISP430_A2::sequence::attach(const value_type & entry)
	{
	}

	void CISP430_A2::sequence::remove_current()
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

	void CISP430_A2::sequence::resize(size_type new_capacity)
	{
		//This file will allocate new space and release old space depending on if new_capacity > used.

		//Assert if 
	}

	void CISP430_A2::sequence::operator=(const sequence &)
	{
	}

	size_t CISP430_A2::sequence::size() const
	{
		return used;
	}

	bool CISP430_A2::sequence::is_item() const
	{
		//Check if there is an item in the current element.
		if (current_index > used)
		{
			//If current_index greater, return false to is_item call.
			return false;
		}
		else
		{
			//Else, return true.
			return true;
		}
	}

	double CISP430_A2::sequence::current() const
	{
		//If is_item is true when called, return the value of the current item to call.
		return data[current_index];
	}

	CISP430_A2::sequence::~sequence()
	{
		delete[] data;
	}
}
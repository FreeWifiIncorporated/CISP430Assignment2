/*
	Nathan Yarrison
	CISP 430
	9/20/2017
	Assignment 2: Sequence 2 project
*/
// This is the implementation program will create a dynamically allocated sequence of numbers that can grow and shrink in size.

#include "sequence2.h"
#include <cstdlib>

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

		//Shift original items to the right one to make room for the new item.
		for (int i = used; data[i] > 0; --i)
		{
			data[i] = data[i - 1];
		}

		//Add new entry to the front of the sequence (data[0]).
		data[0] = entry;
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

	size_t CISP430_A2::sequence::size() const
	{
		return used;
	}

	bool CISP430_A2::sequence::is_item() const
	{
		//Check if there is an item in the current element.
		if (data[current_index] != )
		return false;
	}

	double CISP430_A2::sequence::current() const
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

	CISP430_A2::sequence::~sequence()
	{
		delete[] data;
	}
}
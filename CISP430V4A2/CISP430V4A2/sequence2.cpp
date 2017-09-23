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
		: capacity(entry.capacity), used(entry.used), current_index(entry.current_index) //Initialize values for copy-constructor.
	{
		data = new value_type[capacity];

		for (size_type index = 0; index < entry.used; ++index)
		{
			data[index] = entry.data[index];
		}
	}

	void CISP430_A2::sequence::start()
	{	
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

		//Check if size is greater than capacity. If it is, then increase the capacity by 10%
		if (size() >= capacity)
		{
			resize(capacity * 1.1); //Call resize to change the size of the capacity
		}

		if (!is_item())
		{
			//This checks if there is an item and if there isn't. sets current_index to 0 so that the new item is added at the front of the sequence.
			current_index = 0;
		}


		//Shift original items to the right one to make room for the new item.
		for (size_type i = size(); i > current_index; --i)
		{
			//Assign value from the previous index to the current index, one item at a time.
			data[i] = data[i - 1]; //Shifts items in sequence
		}

		++used;

		//Add new entry to the front of the sequence (data[0]).
		data[current_index] = entry;
	}

	void CISP430_A2::sequence::attach(const value_type & entry)
	{
		if (size() > capacity) // 
		{
			resize(size_type(capacity * 1.1)); // if so increase the capacity by 10%
		}

		if (!is_item()) //Checks if there is or is not an item in the current element.
		{
			//If not, assign current_index to the size of the sequence to add the item to the end of the sequence.
			current_index = size();
		}
		else
		{
			//Else, increment current_index by 1 to add item to the next element in the list.
			current_index++; // to insert after current item
		}
			
		for (size_type i = size(); i > current_index; --i)
		{
			//Assign value from the previous index to the current index, one item at a time.
			data[i] = data[i - 1]; //Shifts items in sequence.
		}
		
		++used; //Increase the value of used to keep track of how many items there are in the sequence.

		data[current_index] = entry; // new item is now the current item
	}

	void CISP430_A2::sequence::remove_current()
	{
		//Removes the current item from the index.
		for (size_type i = current_index + 1; i < used; i++)
		{
			data[i - 1] = data[i]; //Takes an item in the sequence and moves it to the element before, removing the current item by shifting every item after over to the left
		}

		--used; //Decrements used by 1 because there is now one less item in the sequence.
	}

	void CISP430_A2::sequence::resize(size_type newSize)
	{
		//This file will allocate new space and release old space depending on if new_capacity > used.
		
		//Check if newSize is greater than the size of the current sequence.
		if (newSize > used)
		{
			//If it is, assign the newSize to capacity to increase capacity.
			capacity = newSize;

			value_type* tempData = new value_type[capacity];

			for (size_type index = 0; index < size(); ++index)
			{
				//Copies data over to a temporary location.
				tempData[index] = data[index];
			}

			data = tempData; //Assigns values in temp location to new data.
		}
	}

	void CISP430_A2::sequence::operator=(const sequence & otherSequence)
	{
		resize(size_t(otherSequence.capacity)); //Calls resize to change the capacity of the new sequence.
		used = otherSequence.used; // Assigns the used value of the passed over sequence to the new value of used.
		current_index = otherSequence.current_index; // MIGHT CAUSE A PROBLEM IF IT NEEDS TO BE THE SAME INDEX AS THE PREVIOUS FOR THE EXAM

		for (size_type index = 0; index < used; ++index)
		{
			//For all values of index less than used, assign values from otherSequence.data[] to data[].
			data[index] = otherSequence.data[index];
		}
	}

	size_t CISP430_A2::sequence::size() const
	{
		return used; //Returns value of used, which is the size of the sequence.
	}

	bool CISP430_A2::sequence::is_item() const
	{
		//Check if there is an item in the current element.
		return (current_index < used); //Return boolian result.
	}

	double CISP430_A2::sequence::current() const
	{
		//If is_item is true when called, return the value of the current item to call.
		return data[current_index];
	}

	CISP430_A2::sequence::~sequence()
	{
		delete[] data; //Delete sequence.
	}
}
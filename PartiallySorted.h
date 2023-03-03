#pragma once
#include <iostream>
#include<string>
using namespace std;

template <typename T>
class PartiallySortedList {
private:
	//Fields
	string* stringData;
	int size{0}; //TODO maybe initionalize
	int capacity{10};

public:

	//Empty Constructor
	PartiallySortedList() {
		stringData = new string[capacity];
	}

	//Destructor
	~PartiallySortedList() {
		delete[] stringData;
	}

	//Copy constructor
	PartiallySortedList(const PartiallySortedList<string>& other) {
		capacity = other.capacity;
		size = other.size;
		stringData = new string[capacity];
		//Go through
		for (int i = 0; i < size; i++) {
			//Copy all the real items
			stringData[i] = other.data[i];
		}
	}

	//Copy assignment operator
	PartiallySortedList operator=(const PartiallySortedList<string>& other) {
		//Delete old stuff
		delete[] stringData;

		//Mimic the copy constructor
		capacity = other.capacity;
		size = other.size;
		stringData = new string[capacity];
		//Go through
		for (int i = 0; i < size; i++) {
			//Copy all the real items
			stringData[i] = other.data[i];
		}
	}
	void expand() {

		string* tmp = new string[capacity * 2];
		//Copy contents
		for (int i = 0; i < capacity; i++) {
			tmp[i] = stringData[i];
		}
		//Delete the old data
		delete[] stringData;
		//Swap!
		stringData = tmp;
		tmp = nullptr;
		capacity *= 2;
	}

	/*
	* Either the value is going to be added before another string because
	* it has the same length or a larger length than value's length. Otherwise it should
	* be added at the end of the arraylist.
	*/
	bool add(string value) {
		// Check if the capacity of the arraylist needs to be expanded
		if (size + 1 > capacity) {
			this->expand();
		}

		// Check if size is equal to 0 and there is nothing to compare values length to
		if (size == 0) {
			// insert value at the first slot in the arraylist since it is currently empty
			stringData[0] = value;
			// increment size since a new value was added
			size++;
			return false; // return false because the loop isn't used
		}
		else {
			// Loop through stringData until a suitable spot is found
			for (int i = 0; i < size; i++) {
				// Check if the value should be inserted at the given index or continue looping
				if (stringData[i].length >= value.length) {
					// Loop to make room for the new value being inserted
					for (int j = size - 1; j > i; j--) { // FIXME - check if condition makes sense
						// Moves the current index back one slot in the array
						stringData[j] = stringData[j - 1];
					}
					// Enters in the new value at the avalible index
					stringData[i] = value;
					// Increment size since a new value was added
					size++;
					// use return to end the loop early since we only need to insert one value at a time
					return false; // could be used to make the distinction of when only part of the loop was used
				}
			}

			/*
			* If the loop doesn't find a spot for value, then value must have a length
			* larger than the rest and should be put at the end.
			*/
			stringData[size] = value;
			// Increment size since a new value was added
			size++;
			return true; // could be used to make a distinction of when the entire loop was used
		}
	}
	
	string get(int index) {
		return stringData[index];
	}

	int getSize() {
		return size;
	}


};

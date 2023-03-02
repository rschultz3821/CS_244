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

	//Append onto the end of the arraylist
	// Note: not expanding array yet
	void add(string value) {
		if (size + 1 > capacity) {
			this->expand();
			size++;
		}
		// figure out where the new value should be added
		for (int i = 0; i < size; i++) {
			if (stringData[i].length == value.length) {
				for (int j = i; j < size - i + 1; j++) {
					stringData[j + 1] = stringData[j];
				}
				stringData[i] = value;
			}
		}
	}

	int getSize() {
		return size;
	}


};

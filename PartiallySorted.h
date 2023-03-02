#pragma once
#include <iostream>
#include<string>
using namespace std;

//template <typename T>
class PartiallySortedList {
private:
	//Fields
	string* stringData;
	int size{}; //TODO maybe initionalize
	int capacity{};

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
	void append(string value) {
		if (size + 1 > capacity) {
			this->expand();
		}
		stringData[size++] = value; // 1
	}

	int getSize() {
		return size;
	}


};

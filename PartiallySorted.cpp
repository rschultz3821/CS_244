#include <iostream>
#include <string>
#include <array>
#include "PartiallySorted.h"
using namespace std;

// STRING TESTING
void partiallySortedStringTesting() {
	// Test partially sorted String
	cout << "PartiallySortedString tests" << endl << "************" << endl;

	// test getters
	PartiallySortedString str1{ "testing" };
	if (str1.getStr() != "testing") {
		throw "Get string is not working right.";
	}
	else {
		cout << "PartiallySortedString getter working" << endl;
	}

	// test setters
	str1.setStr("setter");
	if (str1.getStr() != "setter") {
		throw "Set string is not working right.";
	}
	else {
		cout << "PartiallySortedString setter working" << endl;
	}
	// test == - true if same length and same characters in order
	PartiallySortedString str2{ "tree" };
	PartiallySortedString str3{ "tree" };
	if (str2 == str3) {
		cout << "Operator== success" << endl;
	}

	// test |= - true if same length
	str3.setStr("test");
	if (str2 |= str3) {
		cout << "Operator|= success" << endl;
	}

	// test > - if first is greater than 
	str3.setStr("tye");
	if (str2 > str3) {
		cout << "Operator> success" << endl;
	}

	// test < - if first is less than
	str3.setStr("testing");
	if (str2 < str3) {
		cout << "Operator< success" << endl;
	}
}

// LIST TESTING
// Test partially sorted list
void runListTests() {
	// Test getSize - returns expected size(could test in add)
	// Test add - expand? - size 0 return false - check if it made it to a certain char ending
	/*
	* This tests add, expand, and getSize - this is because this method adds strings to the arraylist, 
	* checks the size, and has to expand the arraylist to get to 11.
	*/
	PartiallySortedList<string> list1{};
	array<string, 11> strArr = { "checkmate in 2", "11 hats", "12 Monkeys", "300 camels", "water bottle",
		"penguin", "pug", "tiger", "apple", "grape", "hi" };

	cout << "--------------------------------------------------------------------------------------------------------------------\n";
	cout << "Running list tests\n";
	for (int i = 0; i < strArr.size(); i++) {
		list1.add(strArr[i]);
		if (list1.getSize() == i + 1) {
			cout << "Success! The current size is " << list1.getSize() << " it should be " << i + 1 << endl;
		}
		else {
			cout << "Failed! The current size is " << list1.getSize() << " it should be " << i + 1 << endl;
		}
	}


	// Test get - returns expected value	
	// Test Count permutations - check if grouplist is size 0
}

// Runs tests
int main() {
	partiallySortedStringTesting();
	cout << "\n\n";
	runListTests();
};



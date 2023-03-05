#include <iostream>
#include<string>
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
template <typename T>
void listTest() {
	// Test partially sorted list
	PartiallySortedList<string> list1{};
	// Test get - returns expected value
	

	// Test getSize - returns expected size(could test in add)
	// Test add - expand? - size 0 return false - check if it made it to a certain char ending
	// Test Count permutations - check if grouplist is size 0
}

int main() {

	partiallySortedStringTesting();
};

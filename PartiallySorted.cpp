/**
 * This is the test class for partially sorted list and string.
 * 
 * @authors Rachel Schultz and Mason Campbell
 * @version 3/7/2023
*/
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
	else {
		cout << "operator|= not working properly" << endl;
	}

	// test > - if first is greater than 
	str3.setStr("tye");
	if (str2 > str3) {
		cout << "Operator> success" << endl;
	}

	// test < - if first is less than
	str3.setStr("testing");
	if (str2 < str3) {
		cout << "Operator< success" << endl << endl;
	}

	PartiallySortedString str5{ "6 cups of coffee" };
	PartiallySortedString str6{ "6 cups of coffee" };
	PartiallySortedString str7{ "6 cups of coffees" };
	//Testing operators to make sure they FAIL
	if (str6 == str7) {
		cout << "Operator== success" << endl;
	}
	else {
		cout << "Operator== fails successfully" << endl;
	}
// 100 commit just cuz
	if (str6 |= str7) {
		cout << "Operator|= success" << endl;
	}
	else {
		cout << "Operator|= fails successfully" << endl;
	}

	if (str5 > str7) {
		cout << "Operator> success" << endl;
	}
	else {
		cout << "Operator> fails successfully" << endl;
	}

	if (str7 < str5) {
		cout << "Operator< success" << endl;
	}
	else {
		cout << "Operator< fails successfully" << endl;
	}
}

// LIST TESTING
// Test partially sorted list
void runListTests() {
	// Test getSize - returns expected size(could test in add)
	// Test add - expand? - size 0 return false - check if it made it to a certain char ending
	/*
	* This tests add, expand, and getSize - this is because this method adds strings to the arraylist,
	* checks the size, and has to expand the arraylist to get to 11. Also none of this would be possible without
	* the constructor, so it is also testing the constructor
	*/
	PartiallySortedList<string> list1{};
	array<string, 11> strArr = { "checkmate in 2", "11 hats", "12 Monkeys", "300 camels", "water bottle",
		"penguin", "pug", "tiger", "apple", "grape", "hi" };

	cout << "--------------------------------------------------------------------------------------------------------------------\n";
	cout << "Running list tests\n";
	cout << "Test if getSize, expand, and add all work correctly" << endl;
	// Loop through the array to add all the strings to the arraylist
	for (int i = 0; i < strArr.size(); i++) {
		// add strings to the array list
		list1.add(strArr[i]);
		// Check if the current size of the array is correct or not
		if (list1.getSize() == i + 1) {
			cout << "Success! The current size is " << list1.getSize() << " it should be " << i + 1 << "." << endl;
		}
		else {
			cout << "Failed! The current size is " << list1.getSize() << " it should be " << i + 1 << "." << endl;
		}
	}
	// spacing
	cout << "\nTest if get works correctly" << endl;
	// Test get - returns expected value	
	array<string, 11> newStrArr = { "hi", "pug", "grape", "apple", "tiger", "penguin", "11 hats", "300 camels",
		"12 Monkeys", "water bottle", "checkmate in 2" };
	// Loop through the array to see if get works and the values are in the correct order.
	for (int i = 0; i < newStrArr.size(); i++) {
		// Checks whether the values are in the correct order or not. 
		if (list1.get(i) == newStrArr[i]) {
			cout << "Success! The current value in the list is " << list1.get(i) << " it should be " << newStrArr[i] << "." << endl;
		}
		else {
			cout << "Failed! The current value in the list is " << list1.get(i) << " it should be " << newStrArr[i] << "." << endl;
		}
	}

	// make a variable so we only call countPermutations once
	int perms{ list1.CountPermutations() };
	
	// spacing
	cout << endl;

	// Test Count permutations - check if grouplist is size 0
	if (perms == 24) {
		cout << "Success! The current number of permutations is " << perms << " it should be " << 24 << "." << endl;
	}
	else {
		cout << "Failed! The current number of permutations is " << perms << " it should be " << 24 << "." << endl;
	}

	// spacing
	cout << endl;

	// test factorial method
	cout << "Factorial test 5! = 120 comes out to be: " << list1.factorial(5) << endl;
	cout << "Factorial test 4! = 24 comes out to be: " << list1.factorial(4) << endl;
}

// Runs tests
int main() {
	// tests ps string
	partiallySortedStringTesting();
	// spacing
	cout << "\n\n";
	// tests ps lists
	runListTests();
};


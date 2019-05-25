//============================================================================
// Name        : advance_c_pp_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Person {

private:
	string name;
	int age;

public:
	//constructor
    //Person():name(name), age(age) {};

	// intialize variables
	Person(string name, int age): name(name), age(age){
	};
	 /* same as this
	Person(string name, int age){
			this->name = name;
			this->age = age;
		};
   */


	void print() {
		cout << name << ":" << age << endl;
	}
};

int main() {

	// ---------vector---------
	// vector is resizable, it handles the memory for you unlike array
	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	cout << strings[2] << endl;
	cout << "vector size is: " << strings.size() << endl; // now it becomes 6

	// not recommended
	/*
	 for (int i=0; i < strings.size(); i++) {
	 cout << strings[i] << endl;
	 }
	 */

	// declare the variable "it" and set it to strings.begin()
	// 'it' is a pointer
	/* you can do something like this to increment it
	 vector<string>::iterator it = strings.begin();
	 cout << *it << endl;
	 it++;
	 cout << *it << endl;
	 */

	//so you can do this to loop thru a vector
	for (vector<string>::iterator it = strings.begin(); it != strings.end();
			it++) {
		cout << *it << endl;
	}

	//how vector manages memory - capacity
	vector<double> numbers(20); // predefined size of 20
	cout << "Size of vector: " << numbers.size() << endl;

	int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	for (int i = 0; i < 100; i++) {
		if (numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
		}
		numbers.push_back(i);
		//cout << "Size of vector: " << numbers.size() << endl;
	}

	// --------multi-dimention vector-----
	// This means:
	// a variable named grid that is the type of vectpr
	// with predefined size of 3
	// each element is a vector
	// with predefined size of 4
	// each emlement is int, initialized value of 7
	vector<vector<int> > grid(3, vector<int>(4, 7));
	for (int row = 0; row < grid.size(); row++) {
		for (int col = 0; col < grid[row].size(); col++) {
			cout << "value: " << grid[row][col] << endl;
		}
	}

	//----------list----------
	// with list, you can insert items to anywhere
	// vector you can only push to the last
	list<int> myList;
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_front(0);

	// insert element
	list<int>::iterator itr = myList.begin();
	cout << "Elemt:" << *itr << endl;
	itr++;
	itr++;
	myList.insert(itr, 100);

	// remove second element
	list<int>::iterator erase_itr = myList.begin();
	erase_itr++;
	myList.erase(erase_itr);

	// change things in the fly
	for (list<int>::iterator it = myList.begin(); it != myList.end(); it++) {
		if (*it == 3) {
			myList.insert(it, 20);
		}

		if (*it == 2) {
			myList.erase(it);
		}
	}

	// coutput the list
	for (list<int>::iterator it = myList.begin(); it != myList.end(); it++) {
		cout << *it << endl;
	}

	//-------mao-------------
	map<string, int> ages;
	ages["Hsin"] = 38;
	ages["Jess"] = 35;
	ages["Kyle"] = 6;

	cout << ages["Hsin"] << endl;

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		cout << it->first << ": " << it->second << endl; // print out the key

	}

	// find if a key exists in map
	if (ages.find("Kyle2") != ages.end()) {
		cout << "Found Kyle" << endl;
	} else {
		cout << "Kyle not found" << endl;
	}

	// pair - you can use this when looping thru the map
	pair<string, int> mypair("Ken", 30);
	cout << mypair.first << endl;

	//insert a pair into map
	ages.insert(mypair);
	cout << "Ken's age is :" << ages["Ken"] << endl;

	//make_pair function
	ages.insert(make_pair("Peter", 30));

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
		pair<string, int> age = *it;
		cout << "First element:" << age.first << endl;
	}

	map<string name, int age> people;

	return 0;
}


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
#include <set>
#include <queue>
#include <stack>

using namespace std;

class Man {
private:
	string name;
	int age;

public:
	Man() :
			name(""), age(0) {
	}
	;

	Man(string name, int age) :
			name(name), age(age) {
	}

	~Man() {
//		cout << "Object destroyed" << endl;
	}

	bool operator<(const Man &other) const {
		return name < other.name;
	}
	;

	// friend the prototype of the function
	// this will allow the function to access private variables
	friend bool comp(const Man &man1, const Man &man2);

	string get_name() {
		return name;
	};
	void say_hi() const {
		cout << "Hi my name is " << name << " and I am " << age << endl;
	}
};

class Person {

private:
	string name;
	int age;

public:
	//constructor with no parameter
	Person() :
			name(""), age(0) {
	}
	;

	// intialize variables
	Person(string name, int age) :
			name(name), age(age) {
	}
	;
	/* same as this
	 Person(string name, int age){
	 this->name = name;
	 this->age = age;
	 };
	 */
	// copy constructor
	Person(const Person &other) {
		cout << "Copy constructor running for" << other.name << endl;
		name = other.name;
		age = other.age;
	}

	// operator overloading for less than - this is needed if you want to use Obj as key
	// you need to tell C++ how to compare the objects
	// the "const" keywords are needed for both the parameter and return
	bool operator<(const Person &other) const {
		// if you only compare the name then as long as name is the same they will be considered the same key
		if (name == other.name) {
			return age < other.age;
		}
		return name < other.name;
	}

	void print() const {
		cout << name << ":" << age << endl;
	}
};

bool comp(const Man &man1, const Man &man2) {
	// by default, class variables are private
	// to keep them private but make it available in a function like this
	// we add "friend" in the class implementation
	return man1.name < man2.name;
}
;

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

	//-------map-------------
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

	map<int, Person> people;

	// map needs the default constructor (no parameters)
	// it creates the instance without parameters and then do the assignment
	// btw this won't trigger copy constructor
	people[0] = Person("Mike", 40);
	// this will trigger copy constructor
	// by default c++ provides shallow copy for assignment which copies the variables
	// if you don't want that you can create your copy constructor
	people.insert(make_pair(1, Person("Bob", 45)));

	// ------------operator overriding--------------
	// let's use custom objects as key in maps
	// a few gotchas here:
	// key has to be const - make sure you use const keyword
	// in order for C++ to use objects as key, it has to be able to sort those keys
	// that means you have to implement your custom less than operator
	// so we have to use operator overloading
	map<Person, int> people_objs;
	people_objs[Person("Hsin", 39)] = 39;
	people_objs[Person("Kyle", 6)] = 6;

	for (map<Person, int>::iterator it = people_objs.begin();
			it != people_objs.end(); it++) {
		it->first.print();
	}

	//--------------multimaps--------------------
	//multimaps can have same keys,
	// to find all same keys you will need some special functions
	multimap<int, string> lookup;
	lookup.insert(make_pair(0, "hello")); //multimap you will to use insert
	lookup.insert(make_pair(0, "wrold"));
	// to find the same keys, use equal_range method
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its =
			lookup.equal_range(0);
	for (multimap<int, string>::iterator it = its.first; it != its.second;
			it++) {
		cout << it->first << ":" << it->second << endl;
	}

	// in c++ 11, you can use the "auto" keyword to simplify
	auto its2 = lookup.equal_range(0);
	for (multimap<int, string>::iterator it = its2.first; it != its2.second;
			it++) {
		cout << it->first << endl;
	}

	//------------set----------------------
	set<int> my_set;
	my_set.insert(10);
	my_set.insert(2);
	for (set<int>::iterator it = my_set.begin(); it != my_set.end(); it++) {
		cout << *it << endl;
	}

	// to find if something is in the set, user .count()
	if (my_set.count(0)) {
		cout << "Find 2" << endl;
	}

	// for custom objs, you need to overload the less than operator, same as map
	set<Man> man_set;
	man_set.insert(Man("Ken", 30));
	man_set.insert(Man("Rob", 45));

	for (set<Man>::iterator it = man_set.begin(); it != man_set.end(); it++) {
		it->say_hi();
	}

	//---------stack-----------
	stack<Man> my_stack;
	// btw, when you do this, it acutally creates a shallow copy
	// and original obj will be destroyed
	my_stack.push(Man("Bob", 30));
	my_stack.push(Man("John", 40));
	my_stack.push(Man("Kevin", 40));
	my_stack.pop();
	my_stack.top().say_hi();

	//invalid code. you can't use the reference once it's poped
//	 Man &test1 = my_stack.top();
//	 my_stack.pop();
//	 test1.say_hi();
//	 my_stack.top().say_hi();

	cout << endl;
	// loop thru the stack
	my_stack.push(Man("Sab", 30));
	while (my_stack.size() > 0) {
		// here, if you just use Man tmp = my_stack.top()
		// it still works, but it creates a shallow copy
		// which is inefficient. Instead, create a reference
		// so when you pop it the obj will be destroyed
		Man &tmp = my_stack.top();
		tmp.say_hi();
		my_stack.pop();
	}

	cout << endl;
	//--------queue-----------
	queue<Man> my_queue;
	my_queue.push(Man("AAA", 20));
	my_queue.push(Man("BBB", 30));
	my_queue.push(Man("CCC", 40));

	my_queue.front().say_hi();
	my_queue.pop();
	my_queue.front().say_hi();
	my_queue.push(Man("DDD", 50));
	my_queue.back().say_hi();

	//------sort vector-------
	// first take a look at sorting an array
	int int_arr[] = { 3, 2, 5 };
	int n = sizeof(int_arr) / sizeof(int_arr[0]);
	sort(int_arr, int_arr + n); // this is like pointer arithmetic
	for (int i = 0; i < 3; i++) {
		cout << int_arr[i] << endl;
	}

	//now vector
	vector<Man> my_vector;
	my_vector.push_back(Man("YYY", 10));
	my_vector.push_back(Man("XXX", 10));
	// this works using operator overloading but the following is coller
	// sort(my_vector.begin(), my_vector.end()); // in order to sort custom object, you need to have operator overloading

	//use comp function in sort
	sort(my_vector.begin(), my_vector.end(), comp);

	for (int i = 0; i < my_vector.size(); i++) {
		my_vector[i].say_hi();
	};

	//------deque-----(double endded data structure
	// main features:
	// - push_back
	// - push_front
	// - pop_top
	// - pop_end

    // code to be added
	cout << endl;

    // -----complex data type------
	// mix different data structures
	// Example: map with vectors
	map<string, vector<Man> > friends;
	friends["A-kun"].push_back(Man("Ken", 30));
	friends["A-kun"].push_back(Man("Bob", 30));
	friends["B-kun"].push_back(Man("Ken", 30));

	for (map<string, vector<Man> >::iterator it=friends.begin(); it != friends.end(); it++){
		cout << it -> first << ":" << flush;

		for (vector<Man>::iterator itr=it->second.begin(); itr != it -> second.end(); itr++){
			cout << itr -> get_name() << ", " << flush;
		};

		cout << endl;
	};

	return 0;
}

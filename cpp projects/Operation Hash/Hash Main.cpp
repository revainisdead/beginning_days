// Christian Hall
//
// 5/31/2013
// Chapter 8 Programming Exercise
// CS 260 - Data Structures

#include <iostream>
#include <iomanip>
#include <string>

#include "hashT.h"
#include "stateData.h"

using namespace std;

int main() {
	stateData state1, state2, state3;
	
	int index = 0;
	
	// Create a hash table of stateData objects
	hashT<stateData> obj(3);
	
	// Put info into three different states
	state1.setStateInfo("Washington", "Olympia", 192100);
	state2.setStateInfo("Oregon", "Notsure", 170000);
	state3.setStateInfo("Fakestate", "Fakecity", 210000);

	// Put the state's info the hash function sorted
	// by the state's name
	index = obj.hashFunc(state1.getName());
	obj.insert(index, state1);

	index = obj.hashFunc(state2.getName());
	obj.insert(index, state2);

	index = obj.hashFunc(state3.getName());
	obj.insert(index, state3);

	cout << "State Information:" << endl;
	obj.print();

	system("pause");
	return 0;
}
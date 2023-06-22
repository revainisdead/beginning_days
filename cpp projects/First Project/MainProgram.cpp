// Christian Hall 4/1/13
// Practice

#include <iostream>
#include <vector>

using namespace std;
#include "record.h"

int main() {
	// Calls default constructor, attempting to
	// initialize variables.
	//Record myRecord(30000.0), yourRecord(40000.0);
	//myRecord.print();
	//yourRecord.print();

	vector <Record> myList;

	Record Object1(1, "One");
	Record Object2(2, "Two");

	myList.push_back(Object1);
	myList.push_back(Object2);

	cout << "Size of myList is " << myList.size() << endl;


	for(int i = 0; i < myList.size(); i++) {
		myList.front().print();
		myList.pop_back();
	}



	system("pause");
	return 0;
}
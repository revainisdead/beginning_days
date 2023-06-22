#ifndef H_Person
#define H_Person

#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Person {
public:
	Person();
	Person(string first, int ID);
	void print();
	int getID();

private:
	string first;
	int ID;
	//vector<string>;
	
};

#endif
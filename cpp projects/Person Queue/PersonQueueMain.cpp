// Christian Hall
// CS 260 - Data Structures
// 5/29/13
// Chapter 8 Lab

#include <queue>
#include <iostream>
#include <string>
#include "Person.h"
#include "comparePerson.h"

using namespace std;

int main() {
	priority_queue<Person, vector<Person>, comparePerson> pq;

	Person one = Person("Chris", 111);
	Person two = Person("Sam", 222);
	Person three = Person("Who", 333);
	Person four = Person("Justdewit", 444);

	Person people[4] = {one, two, three, four};
	
	for(int i = 0; i < 4; i++) {
		pq.push(people[i]);
	}

	while(!pq.empty()) {
		pq.top().print();
		pq.pop();
	}

	system("pause");
	return 0;
}
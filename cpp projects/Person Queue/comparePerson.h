#ifndef H_comparePerson
#define H_comparePerson

#include <string>
#include <iostream>
#include <queue>
#include "Person.h"

using namespace std;

class comparePerson {
public:
	bool operator()(Person& p1, Person& p2) {
		if(p1.getID() > p2.getID()) {
			return true;
		} else {
			return false;
		}
		// Lowest ID gets highest priority.
	}
};

#endif
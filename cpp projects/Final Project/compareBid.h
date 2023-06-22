#ifndef H_compareBid
#define H_compareBid

#include <string>
#include <iostream>
#include <queue>

using namespace std;

class compareBid {
public:
	bool operator()(double & bid1, double & bid2) {
		if(bid1 < bid2)
			return true;
		else
			return false;
		// Highest bid gets highest priority.
	}
};

#endif
// Header file called "record.h"

#ifndef H_RECORD
#define H_RECORD
#include <string>
class Record {
private:
	double income;
	string name;

public:
		Record(double = 0, string = "blank");
		void print();
};

#endif
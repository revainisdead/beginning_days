// Implementation file called "recordimp.cpp"

#include <iostream>
using namespace std;
#include "record.h"

Record::Record(double pay, string inName) {
	income = pay;
	name = inName;
}

void Record::print() {
	cout << "Income = " << income << endl;
	cout << "Name = " << name << endl;
}
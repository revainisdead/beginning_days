// State Data Implementation

#include <iostream>
#include <string>

#include "stateData.h"

using namespace std;

stateData::stateData() {
	name = "";
	capitol = "";
	people = 0;
}

void stateData::setStateInfo(string newName, string newCapitol, int numPeople) {
	name = newName;
	capitol = newCapitol;
	people = numPeople;
}

string stateData::getName() {
	return name;
}

void stateData::print() {
	cout << "State information: " << endl;
	cout << "Name: " << name << endl;
	cout << "Capitol: " << capitol << endl;
	cout << "Number of people: " << people << endl;
}

bool stateData::operator<(const stateData& right) const {
	return (name < right.name);
}

bool stateData::operator<=(const stateData& right) const {
	return (name <= right.name);
}

bool stateData::operator>(const stateData& right) const {
	return (name > right.name);
}

bool stateData::operator>=(const stateData& right) const {
	return (name >= right.name);
}

bool stateData::operator!=(const stateData &right) const {
	return (name != right.name);
}

bool stateData::operator==(const stateData &right) const {
	return (name == right.name);
}

ostream &operator<<(ostream& osObject, const stateData &data) {
	cout << "Name: " << data.name << endl;
	cout << "Capitol: " << data.capitol << endl;
	cout << "Population: " << data.people << endl;
	cout << endl;
	
	return osObject;
}
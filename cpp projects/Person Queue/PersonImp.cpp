// Person Class

#include <vector>
#include "Person.h"

using namespace std;

Person::Person() {
	first = "";
	ID = 0;
}

Person::Person(string firstName, int personID) {
	first = firstName;
	ID = personID;
}

void Person::print() {
	cout << first << ", " << ID << endl;
}

int Person::getID() {
	return ID;
}
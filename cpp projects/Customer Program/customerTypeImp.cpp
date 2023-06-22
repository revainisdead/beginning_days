#include <iostream>
#include <vector>
#include <string>

#include "customerType.h"

using namespace std;

customerType::customerType(string first, string last, string Email, vector<string> Rentals) {
	setCustomerInfo(first, last, Email, Rentals);
}

void customerType::setCustomerInfo(string first, string last, string Email, vector<string> Rentals) {
	firstName = first;
	lastName = last;
	email = Email;
	rentals = Rentals;
}

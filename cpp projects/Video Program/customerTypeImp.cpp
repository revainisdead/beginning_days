#include <iostream>
#include <vector>
#include <string>

#include "customerType.h"

using namespace std;

customerType::customerType() {
	firstName = "";
	lastName = "";
	email = "";
}

void customerType::setCustomerInfo(string first, string last, string Email, vector<string> Rentals) {
	firstName = first;
	lastName = last;
	email = Email;
	rentals = Rentals;
}

void customerType::addRentalToList(string rental) {
	rentals.push_back(rental);
}

string customerType::getEmail() {
	return email;
}

vector<string> customerType::getRentals() {
	return rentals;
}

bool customerType::operator==(const customerType& other) const
{
    return (lastName == other.lastName);
}

bool customerType::operator!=(const customerType& other) const
{
    return (lastName != other.lastName);
}

ostream& operator<< (ostream& osObject, const customerType& customer)
{
    osObject << endl;
    osObject << "First Name: " << customer.firstName << endl;
    osObject << "Last Name: " << customer.lastName << endl;
	osObject << "Email address: " << customer.email << endl;
	osObject << "Movies currently rented: ";
	for (int i = 0; i < customer.rentals.size(); i++) {
		osObject << "--" << customer.rentals.at(i) << "--";
	}
	cout << endl;
    return osObject;
}
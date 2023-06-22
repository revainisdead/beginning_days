#ifndef H_customerType
#define H_customerType

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class customerType {
public:
	// get size of vector : how many movies do they have rented
	// if 0, cout : We have hot new movies in tomorrow, come in and 
	// get 1 $ off your next rental

	// Default constructor
	customerType(string firstName = "", string lastName = "", string email = "", vector<string> = {""});

	void setCustomerInfo(string, string, string, vector<string>);

private:
	string firstName;
	string lastName;
	string email;
	vector<string> rentals;


};

#endif
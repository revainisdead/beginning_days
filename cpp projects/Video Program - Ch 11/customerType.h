#ifndef H_customerType
#define H_customerType

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class customerType {
	friend ostream& operator<< (ostream&, const customerType&);

public:
	// Default constructor
	customerType();
	void setCustomerInfo(string, string, string, vector<string>);
	void addRentalToList(string);
	vector<string> getRentals();
	string getEmail();

	bool operator==(const customerType&) const;
    bool operator!=(const customerType&) const;

private:
	string firstName;
	string lastName;
	string email;
	vector<string> rentals;
};

#endif
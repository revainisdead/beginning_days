#include <iostream>

#include "customerListType.h"

using namespace std;

void customerListType::searchCustomerList(string email, bool& found,  
                         nodeType<customerType>* &current) const{
	found = false;
   
    current = first;

    while (current != NULL && !found)
        if (current->info.getEmail() == email) //the item is the same as the item given
            found = true;
        else
		{
            current = current->link;
		}
}

void customerListType::printRentals(string email) {
	bool found = false;
	nodeType<customerType> *location;
	vector<string> printThis;

	searchCustomerList(email, found, location);
	if (found)
		printThis = location->info.getRentals();
	else 
		cout << "Email is not in our directory" << endl;
	
	for(int i = 0; i < printThis.size(); i++) {
		cout << "Movie " << i + 1 << " is: " << printThis.at(i) << endl; // Movie 1, 2, etc.
	}
	system("pause");
}

void customerListType::addRental(string title, string email) {
	bool found = false;
	nodeType<customerType> *location;

	searchCustomerList(email, found, location);

	if (found)
		location->info.addRentalToList(title);
	else 
		cout << "Email is not in our directory" << endl;
}

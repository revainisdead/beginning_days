#ifndef H_customerListType
#define H_customerListType

#include <iostream>
#include <vector>

#include "unorderedLinkedList.h"
#include "customerType.h"

using namespace std;

class customerListType : public unorderedLinkedList<customerType> {
public:
	void printRentals(string); // takes email
	void addRental(string, string); // takes title and email

private:
	void searchCustomerList(string email, bool& found,
                         nodeType<customerType>* &current) const;
};

#endif
// Customer class implementation

#include <iostream>
#include <string>

#include "customer.h"

using namespace std;

ostream &operator<<(ostream& osObject, const customer &data) {
	cout << "Customer's name: " << data.name << endl;
	cout << "Customer's email: " << data.email << endl;
	cout << "***Item's for sale*** " << endl;
	for(int i = 0; i < data.items.size(); i++) {
		cout << "Item " << (i + 1) << ": " << data.items[i];
	}
	cout << "Total commission made: " << data.commission << endl;
	cout << endl;

	return osObject;
}

customer::customer() {
	name = "";
	email = "";
	seller = false;
	commission = 0;
}

void customer::setCustomer(string iName, string iEmail) {
	name = iName;
	email = iEmail;
	
	//item blankItem;
	//items.push_back(blankItem);
}

string customer::getName() {
	return name;
}

void customer::addItem(const item &thing) {
	seller = true;
	// If an item is added, this customer is now a seller.

	items.push_back(thing);
}

string customer::contactInfo() {
	return ("" + name + ", " + email);
}

void customer::addCommission(item &soldItem) {
	double temp;
	temp = soldItem.getPrice();

	commission += (temp / 10);
}

bool customer::searchForItem(string iItemName) {
	for(int i = 0; i < items.size(); i++) {
		if(items.at(i).getName() == iItemName) {
			return true;
		}
	}
	return false;
}

item customer::getItem(string iItemName) {
	item blankItem;
	for(int i = 0; i < items.size(); i++) {
		if(items.at(i).getName() == iItemName) {
			return items.at(i);
		}
	}
	return blankItem;
}

void customer::clearItemList() {
	items.clear();
}

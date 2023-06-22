#ifndef H_customer
#define H_customer

#include <queue>
#include <vector>
#include <string>
#include <iostream>

#include "item.h"

using namespace std;

class customer {
	friend ostream &operator<< (ostream&, const customer&);

public:
	customer();
	void setCustomer(string, string);
	string getName();
	void addItem(const item &);
	string contactInfo();
	void addCommission(item &);
	bool searchForItem(string);
	item getItem(string);

	void clearItemList();

private:
	string name;
	string email;
	bool seller;
	double commission;

	vector<item> items;
};

#endif
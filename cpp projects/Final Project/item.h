#ifndef H_item
#define H_item

#include <iostream>
#include <string>
#include <queue>

#include "compareBid.h"

using namespace std;

class item {
	friend ostream &operator<< (ostream&, const item&);

public:
	item();
	void setInfo(string, double);
	string getName();
	void setSellerInfo(string);
	double getPrice();
	double getBid();
	void setHighestBidder(string);
	void addSoldDate(string);
	void addBid(int);
	int queueSize();
	
private:
	string itemName;
	double price;
	bool sold;
	double highestBid;
	string highestBidder;
	string soldDate;
	string contactInfo;

	priority_queue<double, vector<double>, compareBid> bids;
};

#endif
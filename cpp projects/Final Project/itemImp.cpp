// Item class implementation

#include <iostream>
#include <string>

#include "item.h"

using namespace std;

ostream &operator<<(ostream& osObject, const item &data) {
	cout << data.itemName << " for " << data.price << "$" << endl;
	
	return osObject;
}

item::item() {
	itemName = "";
	price = 0;
	sold = false;
	highestBid = 0;
	contactInfo = "";
	soldDate = "";
}

void item::setInfo(string iItemName, double iPrice) {
	itemName = iItemName;
	price = iPrice;
}

string item::getName() {
	return itemName;
}

void item::setSellerInfo(string sellerInfo) {
	contactInfo = sellerInfo;
}

double item::getPrice() {
	return price;
}

double item::getBid() {
	return highestBid;
}

void item::setHighestBidder(string iHighestBidder) {
	highestBidder = iHighestBidder;
}

void item::addSoldDate(string iSoldDate) {
	sold = true;
	soldDate = iSoldDate;
}

void item::addBid(int bid) {
	bids.push(bid);
}

int item::queueSize() {
	return bids.size();
}

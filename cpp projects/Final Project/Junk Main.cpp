// Christian Hall
//
// 6/6/13
// CS 260 - Data Structures
// Final Project : &Online Junk

#include <iostream> // Cout
#include <string> // String
#include <fstream> // Text file

// 2 containers
#include <vector> // Vector
#include <queue> // Priority queue

#include "customer.h"

void getAuctionInfo(ifstream &infile, vector<customer> &customerList);

string GLOBAL_CURRENT_DATE = "06-09-13";

using namespace std;
int main() {

	ifstream infile;

	infile.open("Auction Info.txt");

	// List of all customers
	vector<customer> customerList;
	//customer blankCustomer;
	//customerList.push_back(blankCustomer);

	// List of all items sold
	vector<item> sold;
	item blankItem;
	sold.push_back(blankItem);

	//for(int i = 0; i < sold.size(); i++) {
	//	sold[i].setInfo("", 0);
	//}


	getAuctionInfo(infile, customerList);

	cout << endl;

	for(int i = 0; i < customerList.size(); i++) {
		cout << customerList[i];
	}

	string tempName;
	string tempItem;
	string dummy;

	string YorN;

	cout << "Do you want to place a bid? (Y/N)" << endl;
	//getline(cin, YorN);
	cin >> YorN;
	getline(cin, dummy);
	
	while (YorN != "N")	{
		cout << "Who are you? " << endl;
		getline(cin, tempName);
		cout << "What item do you want to bid on?" << endl;
		getline(cin, tempItem);

		item myItem;

		bool found = false;

		for(int i = 0; i < customerList.size(); i++) {
			 if(customerList.at(i).searchForItem(tempItem)) {
				// If item is indeed in that list then get it
				myItem = customerList.at(i).getItem(tempItem);
				found = true;
			 }
		}

		if (found == false) {
			cout << "That item is not up for auction." << endl;
			break;
		}

		int bid;
		cout << "Enter a bid for the: " << myItem.getName() << endl;
		cin >> bid;
		getline(cin, dummy);

		double highestBid = myItem.getBid();
		string tempEmail;
		if (bid > highestBid) {
			cout << "You are now the highest bidder!" << endl;
			cout << "Please enter your email: " << endl;
			getline(cin, tempEmail);
			myItem.setHighestBidder(tempEmail);
		}

		if(bid > myItem.getPrice()) {
			myItem.addSoldDate(GLOBAL_CURRENT_DATE);

			string problem = GLOBAL_CURRENT_DATE;
			cout << "The " << myItem.getName() << " is now sold for: " << bid
				<< " on the date: " << problem << endl;
		}

		cout << "Do you want to place a bid? (Y/N)" << endl;
		getline(cin, YorN);
	}
	



	//cout << "All the items that sold: " << endl;
	//for(int i = 0; i < sold.size(); i++) {
	//	cout << sold[i];
	//	cout << endl;
	//}

	//cout << "All customer information: " << endl;
	//for(int i = 0; customerList.size(); i++) {
	//	cout << customerList[i];
	//	cout << endl;
	//}

	system("pause");
	return 0;
}

void getAuctionInfo(ifstream &infile, vector<customer> &customerList) {

	string customerName;
	string customerEmail;
	string tempItemName = "not#";
	double tempItemPrice = 0;
	string dummy;

	customer currentCustomer; // Customer Object
	item currentItem; // item Object

	getline(infile, customerName);

	while(infile) {
		// Format
		// Name
		// email
		// item 1
		// price
		// item 2
		// price
		// etc
		// END

		getline(infile, customerEmail);

		currentCustomer.setCustomer(customerName, customerEmail);
		// Set customer info

		getline(infile, tempItemName);

		while(tempItemName != "#") {
			infile >> tempItemPrice;
			getline(infile, dummy);

			currentItem.setInfo(tempItemName, tempItemPrice);
			// Set item info

			currentCustomer.addItem(currentItem);
			// Add item to customer's items for sale list

			getline(infile, tempItemName);
		}

		currentItem.setSellerInfo(currentCustomer.contactInfo());

		customerList.push_back(currentCustomer);

		getline(infile, customerName);

		currentCustomer.clearItemList();
		// Clear the currentCustomer's item's vector
	}

}
// Christian Hall
// 4/14/14
// CS 260 - Data Structures using C++

// Stock Market Program

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <iomanip>

#include "stockType.h"
#include "stockListType.h"

using namespace std;

stockListType getData(ifstream& infile);
void printStockData(ofstream& outfile, stockListType stockLIST, vector<stockType> theVector);

double CLOSING_ASSETS = 0; // Getting the total assets.

int main() {
	ifstream infile;
	ofstream outfile;

	infile.open("stockData.txt");

	// Just in case we don't reach the file.
	if(!infile) {
		cout << "File needed can not be accessed "
			 << "or does not exist. " << endl;
	}

	outfile.open("stockDataOut.txt");

	stockListType mainLIST = getData(infile);
	
	outfile << "*********  First Investor's Heaven  **********" << endl;
	outfile << "*********     Financial Report       **********" << endl;
	outfile << "Stock        Today             Previous  Percent" << endl;
	outfile << "Symbol Open   Close  High    Low  Close  Gain Volume" << endl;
	outfile << "------ ----   -----  ----    ---  -----  ---- ------" << endl;

	mainLIST.sortList();
	vector<stockType> tempVector = mainLIST.returnList();
	printStockData(outfile, mainLIST, tempVector); // print data
	
	// Change flag so the stockType now knows to compare itself
	// by percent gain/loss opposed to the symbol of the stock.
	for(int i = 0; i < tempVector.size(); i++) {
		tempVector[i].changeFlag();
	}

	mainLIST.sortList(); // sort data again
	outfile << "Sorting Differently: " << endl;
	printStockData(outfile, mainLIST, tempVector); // print resorted data

	system("pause");
	return 0;
}

stockListType getData(ifstream& infile) {
	string symbol;
	double openingPrice;
	double closingPrice;
	double todayHigh;
	double todayLow;
	double prevClose;
	int volume;
	
	stockType tempStock;
	stockListType tempList;

	infile >> symbol;

	// !infile.eof
	while(infile) {
		infile >> openingPrice >> closingPrice >> todayHigh;
		infile >> todayLow >> prevClose >> volume;
		tempStock.setStockInfo(symbol, openingPrice, closingPrice, todayHigh, todayLow, prevClose, volume);
		tempStock.calcPercent(openingPrice, closingPrice);

		CLOSING_ASSETS += (tempStock.showPrices() * tempStock.showShares());

		tempList.insert(tempStock);

		infile >> symbol;
	}
	return tempList;
}

void printStockData(ofstream& outfile, stockListType stockLIST, vector<stockType> theVector) {
	outfile << fixed << showpoint << setprecision(2);

	vector<stockType> thisLIST = stockLIST.returnList();

	/*for(int i = 0; i < stockLIST.getSize(); i++) {
		thisLIST[i].print(outfile);
	}*/
	vector<stockType>::iterator ptr = thisLIST.begin();

	for(; ptr != thisLIST.end(); ptr++) {
		ptr->print(outfile);
	}

	outfile << "Closing Assets: $" << CLOSING_ASSETS << endl;
	// Closing Assets
	for(int sym = 0; sym < 23; sym++) {
		outfile << "-*";
	}
	outfile << endl;
	outfile << endl;
}
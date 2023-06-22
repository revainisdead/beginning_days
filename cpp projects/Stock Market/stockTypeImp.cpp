#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ios>
#include "stockType.h"
#include "stockListType.h"

using namespace std;

// Default Constructor
stockType::stockType() {
	flag = false;
	symbol = "";
	openingPrice = 0;
	closingPrice = 0;
	todayHigh = 0;
	todayLow = 0;
	prevClose = 0;
	volume = 0;
	percentGain = 0;
}

// Overloaded Constructor / Sets info
void stockType::setStockInfo(string sym, double openPrice, double closePrice, double dayHigh,
		double dayLow, double preClose, int v) {
	symbol = sym;
	openingPrice = openPrice;
	closingPrice = closePrice;
	todayHigh = dayHigh;
	todayLow = dayLow;
	prevClose = preClose;
	volume = v;
}

void stockType::print(ostream& outp) {
	outp << left;
	outp << setw(0) << symbol;
	outp.unsetf(ios::left);
	outp << right;
	outp << setw(9) << openingPrice << setw(7) << closingPrice << setw(7);
	outp << todayHigh << setw(7) << todayLow << setw(7) << prevClose << setw(7) << percentGain << "%" << setw(7) << volume << endl;
	outp.unsetf(ios::right);
}

// Shows the change in price today!
double stockType::showPrices() {
	return closingPrice - openingPrice;
}

// Calculates the percent gain or loss and then prints it.
void stockType::calcPercent(double openPrice, double closePrice) {
	percentGain = (closePrice - openPrice) / (openPrice) * 100;  
}

// Shows the volume of shares!
double stockType::showShares() {
	return volume;
}

// Changes the sign of the flag.
void stockType::changeFlag() {
	bool temp = flag;
	flag = !temp;
}

bool stockType::operator==(const stockType& right) const {
	if (flag) // If flag is true
		return (percentGain == right.percentGain);
	else
		return (symbol == right.symbol);
}
bool stockType::operator!=(const stockType& right) const {
	if (flag)
		return (percentGain != right.percentGain);
	else
		return (symbol != right.symbol);
}
bool stockType::operator<=(const stockType& right) const {
	if (flag)
		return (percentGain <= right.percentGain);
	else
		return (symbol <= right.symbol);
}
bool stockType::operator<(const stockType& right) const {
	if (flag)
		return (percentGain < right.percentGain);
	else
		return (symbol < right.symbol);
}
bool stockType::operator>=(const stockType& right) const {
	if (flag)
		return (percentGain >= right.percentGain);
	else
		return (symbol >= right.symbol);
}
bool stockType::operator>(const stockType& right) const {
	if (flag)
		return (percentGain > right.percentGain);
	else
		return (symbol > right.symbol);
}
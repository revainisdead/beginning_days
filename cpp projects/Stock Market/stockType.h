// stockType class
// Overloaded operators > and < go here.

#ifndef H_stockType
#define H_stockType

#include <fstream>
#include <string>

using namespace std;

class stockType {

public:
	stockType(); // Default constructor
	void setStockInfo(string, double, double, double, double, double, int);
	void print(ostream& out);
	double showPrices();
	void calcPercent(double, double);
	double showShares();
	void changeFlag();

	bool operator==(const stockType&) const;
	bool operator!=(const stockType&) const;
	bool operator<=(const stockType&) const;
	bool operator<(const stockType&) const;
	bool operator>=(const stockType&) const;
	bool operator>(const stockType&) const;

private:
	bool flag;
	string symbol;
	double openingPrice;
	double closingPrice;
	double todayHigh;
	double todayLow;
	double prevClose;
	int volume;
	double percentGain;
};
// Don't forget this semi colon.

#endif
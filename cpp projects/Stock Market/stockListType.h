// Get a list of stock type objects

#ifndef H_stockListType
#define H_stockListType

#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include "stockType.h"

using namespace std;

class stockListType {

public:
	stockListType();
	void insert(const stockType& item);
	int getSize();
	void sortList();
	vector<stockType> returnList();

private:
	vector<stockType> LIST;
};
// Don't forget this semi colon.

#endif

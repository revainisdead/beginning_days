#include <string>
#include <vector>
#include <iostream>
#include "stockListType.h"

using namespace std;

// Default constructor
stockListType::stockListType() {
	vector<stockType>LIST(0);
}

void stockListType::insert(const stockType& item) {
	LIST.push_back(item);
}

int stockListType::getSize() {
	return LIST.size();
}

void stockListType::sortList() {
	sort(LIST.begin(), LIST.end());
}

vector<stockType> stockListType::returnList() {
	return LIST;
}
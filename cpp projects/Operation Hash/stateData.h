#ifndef H_stateData
#define H_stateData

#include <iostream>
#include <string>

using namespace std;

class stateData {
	friend ostream &operator<< (ostream&, const stateData&);

public:
	stateData();
	void setStateInfo(string name, string capitol, int people);
	void print();
	string getName();

	bool operator<(const stateData&) const;
	bool operator<=(const stateData&) const;
	bool operator>(const stateData&) const;
	bool operator>=(const stateData&) const;
	bool operator!=(const stateData&) const;
	bool operator==(const stateData&) const;

private:
	string name;
	string capitol;
	int people;
};

#endif
// Christian Hall
// CS 260 - Data Structures
// 05/04/2013
// Make a diamond of stars using a recursive method.

#include <iostream>
#include <string>
 
using namespace std;

int GLOBAL_MAX = 0;

int makeDiamond(int numStars, int spaces, bool flag);

int main() {
	bool flag = false;
	string totalString = "";

	// Get a number from user
	int choice;
	char ch;
	cout << "Enter a number, this number will be the number of lines it takes" << endl;
	cout << "to get to the middle of the diamond: ";
	cin >> choice;
    cin.get(ch);

	GLOBAL_MAX = choice;

	int spaces = choice - 1;
	makeDiamond(1, spaces, flag);

	system("pause");
	return 0;
}

int makeDiamond(int numStars, int spaces, bool flag) {	
	if (numStars == 0) {
		// base case
		return 0;
	} else if (flag) {
		for(int i = 0; i < spaces; i++) {
			cout << " ";
		}

		for(int j = 0; j < numStars; j++) {
			cout << "x ";
		}
		cout << endl;
		
		// Number of spaces go up when numStars go down
		//spaces += 1;
		makeDiamond(numStars - 1, spaces + 1, flag);
	} else {
		for (int i = 0; i < spaces; i++) {
			cout << " ";
		}

		for (int j = 0; j < numStars; j++) {
			cout << "x ";
		}
		cout << endl;

		if (GLOBAL_MAX == numStars) {
			flag = true;
			return makeDiamond(numStars - 1, spaces + 1, flag);
		}
		
		// Number of space go down when numStars go up
		//spaces -= 1;
		return makeDiamond(numStars + 1, spaces - 1, flag);
	}

}
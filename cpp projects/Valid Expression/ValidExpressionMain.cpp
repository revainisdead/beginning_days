// Christian Hall
// CS 260 - Data Structures
//
// Chapter 7 - Stacks
// Programming exercise +5:

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<char> test;
	string exp;
	bool flag = true;
	char ch;

	// cout << "Enter a math expression: " << endl;
	// cin >> exp;

	exp = "{25 + 2}";

	for (int i = 0; i < exp.size(); i++) {
		ch = exp.at(i);

		if (ch == '{' || ch == '[' || ch == '(') {
			test.push(ch);
		}

		if (ch == '}' || ch == ']' || ch == ')') {
			
			if(test.size() == 0) {
				flag = false;
				break;
			}
			test.pop();
		}
	}

	if(test.size() > 0) {
		flag = false;
	}

	if(flag)
		cout << "The expression is valid." << endl;
	else
		cout << "The expression is invalid." << endl;

	system("pause");
	return 0;
}
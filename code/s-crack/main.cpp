// Christian Hall
// substitution cipher crack

#include<iostream> // cin, cout
#include<iomanip>
#include<cstring>
#include<vector> // sizeof()
#include<string> // string
#include<algorithm> // sort
#include<sstream>
#include<cctype>
#include<fstream> //ifstream
#include<array>
using namespace std;

const int n = 26;

const int NUMBER_OF_KEYS = 500;

int main() {
	// Objectives
	// 1. Create random keys
	// 2. Decrypt the ciphertext with that key
	// 3. Test versus english
	// 4. Percentage of english

	// If percentage if > .7%, then put key into a text file


	// Plaintext: "defend the east"
	// key: phqgiumeaylnofdxjkrcvstzwb

	string ciphertext = "giuifg cei iprc";




	// Load alphabet
	char alphabet[n];
	for(int i = 0; i < n; i++) {
		alphabet[i] = 'a' + i;
	}

	// Random keys
	int position;
	string key = ""; //abcde etc.

	// Temp vector
	vector <char> check;

	bool found = false;

	// Holds keys
	vector<string> keys;

	// Make a number of random keys
	for(int start = 0; start < NUMBER_OF_KEYS; start++){
		position = rand() % n;
		check.push_back(alphabet[position]);
		key += alphabet[position];

		while(key.length() < n) {
			 position = rand() % n;
		 
			 if(find(check.begin(), check.end(), alphabet[position]) != check.end()) {
				found = true; 
			 }


			 if(found == true) {
				 found = false;
				 continue;
			 } else {
				 check.push_back(alphabet[position]);
				 key += alphabet[position];
			 }
		}
		
		keys.push_back(key);

		key = "";

		// Reset temp vector check
		check.clear();
	}


	// ----
	// Have keys
	// Change ciphertext with that key

	// Save possible plaintexts
	vector <string> texts;
	string entireText = "";
	string tempWord = "";

	string tempKey;

	char temp;
	string word; // for stream

	// KEEP SPACES
	//istringstream iss(ciphertext);


	// KEYS
	for(int print = 0; print < keys.size(); print++) {
		cout << "Key: " << keys.at(print) << endl;

		tempKey = keys.at(print);
		
		istringstream iss(ciphertext);
		// CIPHERTEXT
		while(iss >> word) {

			for(int it = 0; it < word.length(); it++) {
				 /*For each letter in the ciphertext we need to
				 find the correctsponding letter in the key
				 and then add that letter onto another string

				 Instead of going character to character through ciphertext
				 go word by word
				 Change the text of the word and add it onto the string*/
			


				temp = word.at(it); // current letter of ciphertext
				for(int b = 0; b < n; b++) {
					if(alphabet[b] == temp) {
						tempWord += tempKey.at(b);
						break;
					}

				} // iterate over the alphabet
		
			//texts.push_back(text);

			} // iterate over the word
		
		entireText = entireText + tempWord + " ";
		//cout << "Current entireText " << entireText << endl;

		tempWord = "";
		
		} // each word of ciphertext

		texts.push_back(entireText);

		entireText = "";
	} // 26 keys



	cout << "Now test versus dictionary . . . " << endl;
	system("pause");
	// ---
	// Now, test versus common English

	ifstream infile;

	infile.open("english.txt");

	string line;
	int x;

	string word2;

	string TESTPLAIN;
	
	// Total words in plaintext
	int counterTotal = 0;
	
	// Total English words in plaintext
	int counterVersus = 0;

	cout << "Searching . . . " << endl;
	for(int final = 0; final < texts.size(); final++) {
			
		// FOR EACH POSSIBLE PLAINTEXT,
		// Put each word through the file
			
		istringstream issend(texts.at(final));

		while(issend >> word2) {
			counterTotal++;


			while (!infile.eof()) {
				getline(infile, line);

				if(word2 == line) {
					counterVersus++;
				}

			//char* search = word2;
			//unsigned int current = 0;
			
			//cout << "Searching . . ." << endl;
			//while(getline(infile, line)) { // I changed this, see below
			//	current++;
			//
			//	if (line.find(search, 0) != string::npos) {
			//		// If an instance of the word was found, then add

			//	}


			//}
			}



		}

		//cout << "Current plaintext tested (" << texts.at(final) << ") " << endl;
		//cout << "English words found: " << counterVersus << endl;

	}


	cout << "English words found: " << counterVersus << endl;
	

	system("pause");
	return 0;
}
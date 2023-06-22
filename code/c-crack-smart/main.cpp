// Christian Hall
// Cryptology
// Updated: June 12, 2015

// Abstract: 
// Cracks a caesar cipher, figures out the key,
// and reprints the plaintext. Punctuation,
// uppercase and lowercase letters are all
// alloed.

#include <iostream> // cin, cout
#include <iomanip>
#include <cstring>
#include <vector> // sizeof()
#include <string> // string
#include <algorithm> // sort
#include <sstream>
#include <cctype>
#include <fstream> //ifstream
#include <array>

const int n = 26;

using namespace std;

int main() {
	// Plaintext: i am a turtle
	// key 17
	
	string plaintext = "";
	string ciphertext = "z rd r klikcv";
	
	string word = "";

	// Two words so it will never equal 'word'
	string letter1 = "test test";
	string letter2 = "test test";

	int shift1;
	int shift2;
	int shift3;
	int shift4;


	// Load alphabet
	char alphabet[n];
	for (int i = 0; i < n; i++) {
		alphabet[i] = 'a' + i;
	}

	int key;

	string filename;
	ifstream infile;

	cout << "Type the name of the file that has your encrypted text:" << endl\
		 << "(all character and punctuation are allowed)" << endl
		 << "Type 'n' to use a preloaded ciphertext" << endl;

	getline(cin, filename);

	if(filename == "n") {
		// Continue
	}
	else {
		infile.open(filename);
		// Save file contents to ciphertext

		ciphertext = "";

		while(infile >> word) {
			ciphertext = ciphertext + word + " ";
		}

	}


	// Remove puncutation
    for (int i = 0, len = ciphertext.size(); i < len; i++) {
        
		if (ispunct(ciphertext[i])) {
            
			ciphertext.erase(i--, 1);
            len = ciphertext.size();

        }
    }
	//cout << "No punctuation in ciphertext: " << ciphertext << endl;
	cout << endl;

	// Handling Uppercase
	transform(ciphertext.begin(), ciphertext.end(), ciphertext.begin(), ::tolower);
	//cout << "No uppercase letters either: " << ciphertext << endl;
	
	// Read from ciphertext, reset word
	istringstream iss(ciphertext);
	word = "";

	// Save words into a vector
	vector<string> words;

	while(iss >> word) {
		cout << "Current word: " << word << endl;

		words.push_back(word);

		// If it's 1 letter and letter1 is still default,
		// then save to letter1
		if(word.length() == 1 && letter1 == "test test") {
			letter1 = word;
		}
		
		// If letter1 is already saved and it's different than the new word,
		// then save to letter2
		if(word.length() == 1 && letter1 != "test test" && word != letter1) { // && letter1 != letter2
			letter2 = word;
		}
		
	}

	//cout << "Letter1: " << letter1 << endl;
	//cout << "Letter2: " << letter2 << endl;

	char letter1Char;
	char letter2Char;

	// "Convert string to character"
	letter1Char = letter1.at(0);
	letter2Char = letter2.at(0);

	shift1 = letter1Char - 'a';
	shift2 = letter2Char - 'a';

	shift3 = letter1Char - 'i';
	shift4 = letter2Char - 'i';
	

	// Shifts complete

	if(shift1 == shift2)
		key = shift1;
	if(shift2 == shift3)
		key = shift2;
	if(shift3 == shift4)
		key = shift3;
	if(shift4 == shift1)
		key = shift4;

	cout << "Key: " << key << endl;


	// ----
	// Reconstruct plaintext

	char decryptChar;
	string decryptWord = "";

	word = "";
	for(int one = 0; one < words.size(); one++) {
		
		word = words.at(one);

		decryptWord = "";
		for(int two = 0; two < word.length(); two++) {
			decryptChar = word.at(two);

			if((decryptChar - 'a') - key < 0)
				decryptChar = alphabet[26 - (key - (decryptChar - 'a'))];
			else
				decryptChar = alphabet[(decryptChar - 'a') - key];

			decryptWord += decryptChar;
		
		}

		plaintext = plaintext + decryptWord + " ";
	}

	cout << "Final plaintext: " << plaintext << endl;
	
	system("pause");
	return 0;
}
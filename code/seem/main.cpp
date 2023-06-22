// Christian Hall
// Capstone Proof of Concept
// 4/9/15
// CSIA 450 - Capstone

// Synopsis: 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
	// Create a file to write to (of)
	ofstream outfile;
	outfile.open("encrypted.txt");

	// Title
	outfile << "Encrypted files go here (don't tell anybody)" << endl;

	// Variables
	//string plaintext = "I love the weather today this is the SECRET message"; // no commas

	string plaintext = "";
	cout << "Send a message" << endl;
	cout << "--------------" << endl;
	cout << "Christian: ";
	getline(cin, plaintext);

	string currentWord = "";
	int currentLength;
	string key = "xfdprmbqf"; // XFDPRMBQF
	int ID = 0;
	int keyLength = key.length(); 
	int atkey = 0;
	char keychar = ' ';
   	char currentChar = ' ';
	char cipherChar = ' ';
	string cipherTotal = "";
	bool doneWord = false;
	bool dummyflag = true;
	int tof = 0;
	string randomWord = "";
	int randomWordLength;
	int randomChar;

	istringstream iss(plaintext);
	// ignores spaces in a string
	
	int temp;
	while(iss >> currentWord) {

		// Insert a random amount of dummy packets (can be 0)
		tof = rand() % 6;

		cout << "Amount of dummies: " << tof << endl;
		cout << "-------------------" << endl;


		for(int i = 0; i < tof; i++) {
			randomWordLength = rand() %  8 + 1; // Get another length
			for (int j = 0; j < randomWordLength; j++) {
				randomChar = rand() % 25 + 1; // 0 to 25
				randomWord.push_back('a' + randomChar); // string + character
			}
			cout << "Random Word: " << randomWord << endl;

			// Put dummy into file
			for(int k = 0; k < randomWordLength; k++) {
				keychar = key.at(k); // at key

				currentChar = randomWord.at(k);
				// Encrypt dummy: Vigenere cipher conversion

				temp = (currentChar - 'a' + keychar - 'a') % 26;
				cipherChar = 'a' + temp;
				
				
				cipherTotal = cipherTotal + cipherChar;
			}

			// Include ID on same line
			outfile << cipherTotal;
			ID = rand() % 4; // Evens: 2, 4, 6, 8
			ID = (ID + 1) * 2;
			outfile << ID << endl;




			//int temp = randomWord.length();
			//outfile << rand() % 10; // Insert a random location
			
			ID = 0;
			randomWord = ""; // Reset random word
			cipherTotal = "";
		}
		
		cout << endl;
		cout << "Real word: " << currentWord << endl;
		cout << endl;

		currentLength = currentWord.length();

		for (int i = 0; i < currentLength; i++) {
			keychar = key.at(i);
			// key.at(i % key.length());


			currentChar = currentWord.at(i);
            
			// Convert to lower case
			currentChar = tolower(currentChar);


			// Vigenere cipher conversion
			temp = (currentChar - 'a' + keychar - 'a') % 26;
			cipherChar = 'a' + temp;
          
			cipherTotal = cipherTotal + cipherChar;
		} // end for

		// Include ID on same line
		outfile << cipherTotal;
		ID = rand() % 4; // Evens+1: 3, 5, 7, 9
		ID = ((ID + 1) * 2) + 1;
		outfile << ID << endl;


		cipherTotal = ""; 

	  } // end paragraph while



	// Part 2
	//
	//
	//
	//
	//
	//
	//
	//

	cout << "----------------" << endl;
	cout << "Encryption finished. " << endl;
	cout << endl;
	cout << "To DECRYPT: ";
	system("pause");

	
	ifstream infile;
	infile.open("encrypted.txt");

	string title;
	string line = "";
	string EoO;
	string decryptTotal = "";
	string TOTAL = "";

	//int check;

	bool flag = false;
	char keychar2 = ' ';
	char currentChar2 = ' ';
	char decryptChar = ' ';

	int temp2;
	
	string convert;
	int identify = 0;

	// Don't print ID
	string tempLine;

	getline(infile, title);
	while (infile.eof() == false) {
		getline(infile, line);
		
		// First iteration
		for(int i = 0; i < line.length(); i++) {
			identify = 0;
			currentChar2 = line.at(i);

			identify = int(currentChar2);

			// 49 to 57 = 1 - 9
			if(identify > 48 && identify < 58) {
				identify = identify - 48;
				// 49 - 48 = 1, 50 - 48 = 2
			} else {
				
				identify = 2;
			}

			if(i == line.length() - 1)
				// Fake packet or not
				if (identify % 2 == 0) {
					flag = true;
				} else {
					flag = false;
				}

		}

		if (flag == true) {
			flag = false;
			continue;
		}

		tempLine = "";
		cout << endl;
		for(int i = 0; i < line.length(); i++) {
			if(i == line.length() - 1) {
				continue;
			}
			tempLine += line.at(i);
		}

		if(infile.eof() == false) {
			cout << endl;
			cout << "Encrypted: " << tempLine << endl;
		}

		for(int i = 0; i < line.length(); i++) {
			if(i == line.length() - 1) {
				continue;
			}

			
			keychar2 = key.at(i);

			// CURRENT CHARACTER
			currentChar2 = line.at(i);

			temp2 = (currentChar2 - 'a') - (keychar2 - 'a') % 26;
			
			// Difficulties. This represents rotations
			if (temp2 < 0) {
				decryptChar = 'z' + temp2 + 1;
			} else {
				decryptChar = 'a' + temp2;
			}

			// Add each character to the word
			decryptTotal = decryptTotal + decryptChar;

		}

		if(infile.eof() == false) {
			cout << "Decrypted: " << decryptTotal << endl;
		}


		// Keep entire string
		//TOTAL += decryptTotal;
		TOTAL = TOTAL + decryptTotal + " ";


		// Reset temp word
		decryptTotal = "";
	}


	// Final output
	cout << endl;
	cout << "Full decryption: " << TOTAL << "\n\n\n";
	
	system("pause");
	return 0;
} // end of main




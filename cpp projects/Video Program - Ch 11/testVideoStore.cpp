//****************************************************************
// Author: D.S. Malik
//
// This program illustrates how to use the classes videoType and 
// videListType to create and process a list of videos.
//****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <cstdlib>

#include "videoType.h"
#include "videoListType.h"

#include "customerType.h"
#include "customerBinaryTree.h"

using namespace std;

void createVideoList(ifstream& infile, 
                     videoListType& videoList);
void displayMenu();

void createCustomerList(ifstream& infileTwo, customerBinaryTree& customerList);

int main()
{
    videoListType videoList;
    int choice;
    char ch;
    string title;

    ifstream infile;

           //open the input file
    infile.open("videoDat.txt");
    if (!infile)
    {
        cout << "The input file does not exist. "
             << "The program terminates!!!" << endl;
        return 1;
    }

        //create the video list
    createVideoList(infile, videoList);
    infile.close();

	// START HERE -----------------------------

	// Need temp variables in main
	string firstName;
	string lastName;
	string email;
	int numMovies;
	vector<string> rentals;

	string temp = "";
	string tempLast = "";
	string tempEmail = "";
	string NOTHING = "";

	ifstream infileTwo;
	infileTwo.open("customerData.txt");
	
	if(!infileTwo)
		cout << "There is an error with the input file. " << endl;

	customerBinaryTree customerList;
	
	createCustomerList(infileTwo, customerList);

	cout << endl;
	cout << "Please enter customer information." << endl;
	cout << "Enter first name: ";
	getline(cin, firstName);
	cout << endl;
	cout << "Enter last name: ";
	getline(cin, lastName);
	cout << endl;
	cout << "Enter email: ";
	getline(cin, email);
	cout << endl;
	cout << "How many movies do you have rented? ";
	cin >> numMovies;

	// Finish getting the line.
	getline(cin, NOTHING);

	for (int i = 0; i < numMovies - 1; i++) {
		cout << "Name one of your rentals, press enter to name the next one: ";
		getline(cin, temp);
		rentals.push_back(temp);
		cout << endl;
	}
	cout << "Name the last rental: ";
	getline(cin, tempLast);
	rentals.push_back(tempLast);
	cout << endl;

	customerType anotherCustomer;
	anotherCustomer.setCustomerInfo(firstName, lastName, email, rentals);
	customerList.insertFirst(anotherCustomer);



        //show the menu
    displayMenu();
    cout << "Enter your choice (7 and 8 are new options!): ";
    cin >> choice;    //get the request
    cin.get(ch);
    cout << endl;

        //process the requests
    while (choice != 9)
    {
        switch (choice)
        {
        case 1: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
                cout << "The store carries " << title 
                     << endl;
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;

        case 2: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                {
                    videoList.videoCheckOut(title);
                    cout << "Enjoy your movie: " 
                         << title << endl;
					cout << "We also recorded that you have this movie rented." << endl; // New

                }
                else
                    cout << "Currently " << title
                         << " is out of stock." << endl;
            }
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;

        case 3: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                videoList.videoCheckIn(title);
                cout << "Thanks for returning "
                     << title << endl;
            }
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;

        case 4: 
            cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                    cout << title << " is currently in " 
                         << "stock." << endl;
                else
                    cout << title << " is currently out "
                         << "of stock." << endl;
            }
            else
                cout << "The store does not carry " 
                     << title << endl;
            break;

        case 5: 
            videoList.videoPrintTitle();
            break;

        case 6: 
            videoList.print();
            break;

		case 7:
			// check out a video
			// but add that video to the rental vector
			// you now have these videos rented: (aka, function: prints the string in that vector)
			cout << "Enter the title: ";
            getline(cin, title);
            cout << endl;
			cout << "Also enter your email: ";
			getline(cin, tempEmail);

            if (videoList.videoSearch(title))
            {
                if (videoList.isVideoAvailable(title))
                {
                    videoList.videoCheckOut(title);
                    cout << "Enjoy your movie: " 
                         << title << endl;
					cout << "We also recorded that you have this movie rented." << endl; // New
					customerList.addRental(title, email);
					system("pause");
                }
                else
                    cout << "Currently " << title
                         << " is out of stock." << endl;
            }
            else
                cout << "The store does not carry " 
                     << title << endl;
			break;

		case 8:
			cout << "Enter the customer's email: ";
			cin >> tempEmail;
			customerList.printRentals(tempEmail);
			break;

        default: 
            cout << "Invalid selection." << endl;
        }//end switch

        displayMenu();     //display menu

        cout << "Enter your choice: ";
        cin >> choice;     //get the next request
        cin.get(ch);
        cout << endl;
    }//end while

	system("pause");
    return 0;
}

void createVideoList(ifstream& infile, 
                     videoListType& videoList)
{
    string title;
    string star1;
    string star2;
    string producer;
    string director;
    string productionCo;
    char ch;
    int inStock;

    videoType newVideo;

    getline(infile, title);
	
    while (infile)
    {
        getline(infile, star1);
        getline(infile, star2);
        getline(infile, producer);
        getline(infile, director);
        getline(infile, productionCo);
        infile >> inStock;
        infile.get(ch);
        newVideo.setVideoInfo(title, star1, star2, producer,
                              director, productionCo, inStock);
        videoList.insertFirst(newVideo);

        getline(infile, title);
    }//end while
}//end createVideoList

void displayMenu()
{
    cout << "Select one of the following:" << endl;
    cout << "1: To check whether the store carries a "
         << "particular video." << endl;
    cout << "2: To check out a video." << endl;
    cout << "3: To check in a video." << endl;
    cout << "4: To check whether a particular video is " 
         << "in stock." << endl;
    cout << "5: To print only the titles of all the videos."
         << endl;
    cout << "6: To print a list of all the videos." << endl;
	cout <<	"7: Check out a movie in your name." << endl; // New
	cout << "8: See which movies a customer is renting." << endl; // New
    cout << "9: To exit" << endl;
} //end createVideoList

void createCustomerList(ifstream& infileTwo, customerBinaryTree& customerList) {	
	string firstName;
	string lastName;
	string email;
	vector<string> rentals; // Local vector
	customerType newCustomer;

	getline(infileTwo, firstName);

	while(infileTwo) {
		getline(infileTwo, lastName);
		getline(infileTwo, email);

		string temp = "not#";
		getline(infileTwo, temp);

		while(temp != "#") {
			rentals.push_back(temp);
			getline(infileTwo, temp);
		}
		
	    newCustomer.setCustomerInfo(firstName, lastName, email, rentals);
		customerList.insertFirst(newCustomer);

		rentals.clear();
		// Clear local variable before you start getting new info.
		
		getline(infileTwo, firstName);
	}

	cout << "Testing the print function (<<): " << endl;
	customerList.print();
}
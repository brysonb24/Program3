/*ProgramName: Program-3
Author: Bryson Brown

Description:
This program reads in animals from a text file then places the animals in 
a doubly linked list where the head and tail are connected. 
The program will eliminate a given number of animals from the list.
The program will use a multiplier that is input by the user
Every 11th animal will be outputted until the final animal is the winner.

Course: 1063 Data Structures
Semester: Spring 2018
Date: 29 04 2018
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DBHeaderList.h"

using namespace std;

int main()
{
	//Instance for class 
	DBList List;

	//Manipulate when needed
	string first;
	string second;

	int listSize = 0;
	int rand = 0;
	int num = 0;
	int length = 0;

	// enter the random number seed
	cout << "Enter a number that will serve as the random seed:" << endl;

	cin >> rand; // Random Number

	srand(rand);

	
	ifstream fin("animals.txt");
	ofstream outfile("Eliminated_.txt");

	outfile << "//Program Name: Program-3" << endl;
	outfile << "//Author: Bryson Brown " << endl;
	outfile << "//Description: " << endl;
	outfile << "//This program reads in animals from a text file then places the animals in " << endl;
	outfile << "//a doubly linked list where the head and tail are connected." << endl;
	outfile << "//The program will eliminate a given number of animals from the list." << endl;
	outfile << "//The program will use a multiplier that is input by the user" << endl;
	outfile << "//Every 11th animal will be outputted until the final animal is the winner." << endl;
	outfile << "//Semester: Spring 2018" << endl;
	outfile << "//Course: 1063 Data Structures" << endl;
	outfile << "//Date: 4/30/2018" << endl << endl;
	
	//Inserts items
	while (!fin.eof()) {

		fin >> first;

		listSize++;

		List.InsertRear(first);

	}

	//Resets list 
	fin.clear();
	fin.seekg(0, std::ios::beg);

	cout << "Input a number: " << endl;
	cin >> num;

	//Asks user to input a number 1-13
	while (num < 1 || num > 13)
	{
		cout << "Input another number: " << endl;

		cin >> num;
	}
	//Outfiles multiplier 
	outfile << "The multiplier selected: " << num << endl;
	
	//Gives the first animal in list 
	fin >> first;

	outfile << "First: ";
	
	//List is greater than 1
	while (listSize > 1) { 

		length = first.length() * num;

		second = List.checkEvenorOdd(length);

		//Prints every 11th animal
		if (listSize % 11 == 0)
		{
			outfile << "- " << second << endl;

			cout << " " << second << endl;
		}
		else
		{
			cout << " " << second << endl;
		}

		fin >> first;

		listSize--;
	}

	//Prints Results
	List.Print(outfile);
	outfile.close();
}

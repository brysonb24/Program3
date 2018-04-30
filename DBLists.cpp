#include <iostream>
#include <fstream>
#include <string>
#include "DBHeaderList.h"

using namespace std;

int main()
{
	//Instance for class 
	DBList List;

	//Manipulate
	string first;
	string second;

	int listSize = 0;
	int rand = 0;
	int num = 0;
	int length = 0;

	//Enter seeding
	cout << "Enter a number that will serve as the random seed:" << endl;
	cin >> rand;
	srand(rand);

	
	ifstream fin("animals.txt");
	ofstream outfile("Eliminated.txt");

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
	
	

	//Insert items
	while (!fin.eof()) {

		fin >> first;

		listSize++;

		List.InsertRear(first);

	}

	//Resets list
	fin.clear();
	fin.seekg(0, std::ios::beg);

	cout << "Choose a number: " << endl;
	cin >> num;

	//Asks user to input a number 1-13
	while (num > 13 || num < 1)
	{
		cout << "Pick another number: " << endl;

		cin >> num;
	}
	//Outfiles multiplier 
	outfile << "The chosen multiplier: " << num << endl;

	while (!fin.eof())
	{
		//Gives the first animal in list 
		fin >> first;

		outfile << "First: ";
		
		//List is greater than 1
		while (listSize > 1) {

			length = first.length() * num;
			second = List.EvenorOdd(length);

			////Prints every 11th animal
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
	}
	//Prints Results
	List.Print(outfile);
}

#pragma once
#include "table.h"
#include "person.h"
#include <fstream>
#include <iostream>

using namespace std;

Table::Table()
{
	for (int i = 0; i < 20; i++)
	{
		peopleArray[i] = People();
	}

}

Table::Table(const Table& origin)
{
	for (int i = 0; i < 20; i++) {
		//set our array/table of people @ i = copy's array/table of people @ i
		peopleArray[i] = origin.peopleArray[i];
	}
}

Table::~Table()
{
	//cout << "destructor" << endl;
}

void Table::Print()
{
	cout << " --- Important figures in computer science ---" <<  endl << endl;
	for (int i = 0; i < 20; i++)
	{
		peopleArray[i].Print();
	}
}

void Table::Read()
{
	//using ios::in so the file can only be read
	ifstream infile("people.txt", ios::in);

	if (infile.fail())
		exit(-1);

	string first;
	string last;
	string birth;
	string death;
	string contribution;


	int lineNum = 0;
	//as long as its not at the end of the file
	//stores the information from people.txt in the table class array
	while (!infile.eof())
	{
		infile >> first;
		infile >> last;
		infile >> birth;
		infile >> death;
		getline(infile, contribution, '\n');

		peopleArray[lineNum].Set(string(first), string(last), stoi(birth), stoi(death), string(contribution));

		lineNum++;

	}
	infile.close();
}

void Table::firstNameSearch(string searchName)
{
	
	//variables for get function
	string first, last, contribution = "";
	int birth = 0;
	int death = 0;
	//numFound used for the if else statement, makes output look better
	int numFound = 0;
	for (int i = 0; i < 20; i++)
	{

		peopleArray[i].Get(first, last, birth, death, contribution);
		if (first == searchName) { peopleArray[i].Print(); numFound += 1; }
		else if (i == 19 && numFound == 0) { cout << "Not in list\n"; }

	}

}

void Table::lastNameSearch(string searchName)
{
	//cout << "Search by last name: ";
	////name to be searched
	//string searchName;
	//cin >> searchName;
	//cout << "\n";

	//variables for get function
	string first, last, contribution = "";
	int birth = 0;
	int death = 0;
	//numFound used for the if else statement, makes output look better
	int numFound = 0;
	for (int i = 0; i < 20; i++)
	{
		peopleArray[i].Get(first, last, birth, death, contribution);
		if (last == searchName) { peopleArray[i].Print(); numFound += 1; }
		else if (i == 19 && numFound == 0) { cout << "Not in list\n"; }
	}
}

void Table::yearSearch(int from, int to)
{
	/*cout << "--- Search by range of birth years ---";
	cout << "\n";
	cout << "From: ";
	int from;
	cin >> from;
	cout << "\nTo: ";
	int to;
	cin >> to;
	cout << "\n";*/
	

	//variables for get function
	string first, last, contribution = "";
	int birth = 0;
	int death = 0;
	for (int i = 0; i < 20; i++)
	{
		peopleArray[i].Get(first, last, birth, death, contribution);
		if (birth >= from && birth <= to) { peopleArray[i].Print();}
		
	}
}
#include <iostream>
#include <fstream>
#include <string>

#include "person.h"
#include "table.h"

using namespace std;

int menu()
{
	cout << " --- List of commands ---\n";
	cout << " [1] --- Search by first name\n";
	cout << " [2] --- Search by last name\n";
	cout << " [3] --- Search by year\n";
	cout << " [4] --- Print out entire list\n";
	cout << " [5] --- Exit Program\n";
	cout << ":";

	int input;
	cin >> input;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(300, '\n');
	}
	cout << endl;
	
	return input;


}


int main()
{
	cout << "Brady Gresham\nUaid: 010989245\n";
	Table table;
	table.Read();
	

	string searchName = "";
	int from, to = 0;
	bool run = true;
	while (run)
	{
		switch (menu()) 
		{
		case 1:
		{
			cout << "Search by first name: ";
			//name to be searched
			cin >> searchName;
			cout << "\n";

			table.firstNameSearch(searchName); break;

		}
		case 2: 
		{
			cout << "Search by first name: ";
			//name to be searched
			cin >> searchName;
			cout << "\n";
			table.lastNameSearch(searchName); break;
		}
		case 3: 
		{
			cout << "--- Search by year ---\n\n";
			cout << "From:";
			cin >> from;
			cout << "\nTo:";
			cin >> to;
			cout << endl;
			table.yearSearch(from, to); break;
		}
		case 4: table.Print(); break;
		case 5: run = false; break;
		default: cout << "Try again\n\n"; break;

		}

	}
	
	return 0;
}
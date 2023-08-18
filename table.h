#pragma once
#include "person.h"
#include <string>
using namespace std;
class Table
{
public:
    Table();
    Table(const Table& origin);
    ~Table();
    void Print();
    void Read();
    void firstNameSearch(const string searchName);
    void lastNameSearch(const string searchName);
    void yearSearch(const int from, const int to);

private:
	//setting max array size to 20 since that is what we have in the people.txt file
	People peopleArray[20];



};
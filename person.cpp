#pragma once
#include <iostream>
#include "person.h"

using namespace std;

People::People()
{
	std::string firstName = "";
	std::string lastName = "";
	int Birth = 0;
	int Death = 0;
	std::string Contribution;
}

People::People(const People& adam)
{
	firstName = adam.firstName;
	lastName = adam.lastName;
	Birth = adam.Birth;
	Death = adam.Death;
	Contribution = adam.Contribution;
}

People::~People()
{
	//cout << "destructor" << endl;
}

void People::Set(const std::string first, const std::string last, const int birth, const int death, const std::string contribution)
{
	firstName = first;
	lastName = last;
	Birth = birth;
	Death = death;
	Contribution = contribution;
}

void People::Get(std::string& first, std::string& last, int& birth, int& death, std::string& contribution)
{
	first = firstName;
	last = lastName;
	birth = Birth;
	death = Death;
	contribution = Contribution;
}

void People::Print()
{
	
	cout << firstName << " " << lastName << endl;
	cout << "Born: " << Birth << endl;

	//I think this if else statement makes the output look cleaner 
	if (Death > 0){ cout << "Died: " << Death << endl; }
	else if (Death == -1) { cout << "Still active" << endl; }
	else if (Death == 0) { cout << "ERROR: Death year improperly assigned" << endl; }
	
	cout << "Contribution:" << Contribution << endl << endl;

}
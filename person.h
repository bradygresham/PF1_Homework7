#pragma once
#include <string>
class People
{
public:
	//declaring methods
	People();
	People(const People& adam);
	~People();
	void Set(const std::string firstName, const std::string lastName, const int birth, const int death, const std::string contribution);
	void Get(std::string& firstName, std::string& lastName, int& birth, int& death, std::string& contribution);
	void Print();

private:
	std::string firstName;
	std::string lastName;
	int Birth;
	int Death;
	std::string Contribution;
};
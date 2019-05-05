#pragma once
#include <iostream>
using namespace std;
class Employee
{
private:
	string id;
	string firstName;
	string lastName;
	string birthDate;
	char gender;
	string startDate;
	double salary;
public:
	Employee();
	Employee(string);
	Employee(string, string, string, string, char, string, double);
	~Employee();
	void setId(string);
	void setFirstName(string);
	void setLastName(string);
	void setBirthDate(string);
	void setGender(char);
	void setStartDate(string);
	void setSalary(double);


	string getId() const;
	string getFirstName() const;
	string getLastName() const;
	string getBirthDate() const;
	char getGender() const;
	string getStartDate() const;
	double getSalary() const;
	
};


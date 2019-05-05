#include "pch.h"
#include "Employee.h"


Employee::Employee()
{
	 id="-----------";
	 firstName="-----------";
	 lastName = "-----------";
	 birthDate = "-----------";
	 gender='?';
	 startDate = "-----------";
	 salary=0.0;
}

Employee::Employee(string i) {
	id = i;
	firstName = "-----------";
	lastName = "-----------";
	birthDate = "-----------";
	gender = '?';
	startDate = "-----------";
	salary = 0.0;
}

Employee::Employee(string i, string f, string l, string b, char g, string d, double s) {
	id = i;
	firstName =f;
	lastName = l;
	birthDate = b;
	gender = g;
	startDate = d;
	salary = s;
}


Employee::~Employee()
{
}

void Employee::setId(string i) {
	id = i;
}

void Employee::setFirstName(string n) {
	firstName = n;
}

void Employee::setLastName(string n) {
	lastName = n;
}

void Employee::setBirthDate(string b) {
	birthDate = b;
}

void Employee::setGender(char g) {
	gender = g;
}

void Employee::setStartDate(string s) {
	startDate = s;
}

void Employee::setSalary(double s) {
	salary = s;
}

string Employee::getId() const {
	return id;
}

string Employee::getFirstName() const {
	return firstName;
}

string Employee::getLastName() const {
	return lastName;
}

string Employee::getBirthDate() const {
	return birthDate;
}

char Employee::getGender() const {
	return gender;
}

string Employee::getStartDate() const {
	return startDate;
}

double Employee::getSalary() const {
	return salary;
}
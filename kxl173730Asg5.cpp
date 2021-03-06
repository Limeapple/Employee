// Assignment using classes to create and manipulate data from employees
//Written by Kevin Liu for CS 1337, assignment 5, starting March 28 2019 net id= kxl173730

#include "pch.h"
#include <iostream>
using namespace std;
#include <string>
#include "Employee.h"
#include <fstream>
#include <iomanip>
bool readFile(Employee *list, int &size);
void write_text_file( int &size, Employee *list);

int main()
{
	Employee *list = new Employee[100];
	int size = 0;
	string inputId="", userInput="";
	bool userInputInvalid = true, returnToMainMenu=true, fileDoesNotExist=true;
	//read file executes and sees if a file called Employee.txt can be found and read
	readFile(list, size);
	//checks to see if the data in the file is longer than 100 employees, if so computer ends
	if (size > 101)
	{
		cout << "Too many employees in file, exceeded 100" << endl;
		return 0;
	}
	while (returnToMainMenu) {
		//menu
		cout << "Choose an option by typing its number and hitting enter:" << endl;
		cout << endl;
		cout << "	1. Enter new employee information" << endl;
		cout << "	2. Display all employee information in alphabetical order by last name" << endl;
		cout << "	3. Look up an employee by ID" << endl;
		cout << "	4. Remove an employee" << endl;
		cout << "	5. Save all data to Employee.txt and exit" << endl;
		while (userInputInvalid) {
			//validates input
			cin >> userInput;
			if ((userInput.length()!=1)&&(userInput > "5" && userInput < "1"))
				cout << "The input is not a valid option, try again" << endl;
			else
				userInputInvalid = false;
		}
		//if user selects 1, create new employee object and add it to array
		userInputInvalid = true;
		if (userInput == "1") {
			string firstName;
			string lastName;
			string birthDate;
			char gender;
			string startDate;
			double salary;
			//check to see if id is unique, if so proceed else return to main menu
			cout << "Enter the ID for the new employee" << endl;
				cin >> inputId;
				bool idDoesntExist = true;
				for (int i = 0; i < size; i++) {
					if (list[i].getId() == inputId) {
						cout << "The Id already exists" << endl;
						idDoesntExist=false;
					}
					//checks to see if there is room to add employee
					if (size > 101)
					{
						cout << "Reached maximum employee capacity of 100, cannot add employee" << endl;
						break;
					}
				}
				if (idDoesntExist)
				{
					//creates the new employee by asking user for data and creating the new employee at the end
					cout << "Enter their first name" << endl;
					cin >> firstName;
					cout << "Enter their last name" << endl;
					cin >> lastName;
					cout << "Enter their birthdate" << endl;
					cin >> birthDate;
					cout << "Enter their gender" << endl;
					cin >> gender;
					cout << "Enter their start date" << endl;
					cin >> startDate;
					cout << "Enter their salary" << endl;
					cin >> salary;
					if (inputId != "" || firstName != "" || lastName != "" || birthDate != "" || gender != NULL || startDate != "" || salary < 5000) {
						Employee person(inputId, firstName, lastName, birthDate, gender, startDate, salary);
						list[size++] = person;
					}
					else
						cout << "Invalid user, try again" << endl;
					}
					
				
		}
		else if (userInput == "2") {
			//method to sort employee based on name
			bool bSwap;
			Employee temp;
			do
			{
				bSwap = false;
				// Inner loop to do comparisons.
				for (int ix = 0; ix < size - 1; ix++)
				{
					if (list[ix].getLastName() > list[ix + 1].getLastName())
					{
						temp = list[ix];
						list[ix] = list[ix + 1];
						list[ix + 1] = temp;
						bSwap = true;
					}
				}
			} while (bSwap);
			//prints their info
			cout << "Information about the employee" << endl;
			for (int i = 0; i < size; i++) {
				cout << list[i].getFirstName() << " " << list[i].getLastName() << endl;
				cout<<setw(2)<< list[i].getGender() << " " << list[i].getId() << endl;
				cout <<setw(5)<< list[i].getBirthDate() << endl;
				cout <<setw(5)<< list[i].getStartDate() << endl;
				cout <<setw(4)<<"$"<< round(list[i].getSalary()) << endl;
			}
		}
		//provides info on a specific employee based on id
		else if (userInput == "3") {
			cout << "Enter the ID of the employee" << endl;
			cin >> inputId;
			bool notFound = true;
			for (int i = 0; i < size; i++)
			{
				//finds employee and prints their info
				if (list[i].getId() == inputId) {
					cout << "Information about the employee" << endl;
					cout << setw(2)<<list[i].getFirstName() << " " << list[i].getLastName() << endl;
					cout<< setw(5) << list[i].getGender() << " "<<list[i].getId()<< endl;
					cout << setw(5) << list[i].getBirthDate() << endl;
					cout << setw(5) << list[i].getStartDate() << endl;
					cout << setw(4) << "$"<<round(list[i].getSalary()) << endl;
					notFound = false;
				}

			}
			if(notFound)
			{
				cout << "Employee not found" << endl;
			}
		}
		//remove employee if their id matches input
		else if (userInput == "4") {
			bool employeeNotFound = true;
			cout << "Enter the ID of the employee" << endl;
			cin >> inputId;
			for (int i = 0; i < size; i++) {
				//manipulate array to fill gap after removing employee
				if (list[i].getId() == inputId) {
					size--;
					for (int b = i; b < size; b++)
					{
						list[i] = list[i + 1];
					}
					cout << "Employee removed" << endl;
					employeeNotFound=false;
				}
				
			}
			if (employeeNotFound)
				cout << "Employee not found" << endl;
			
		}
		//prints employee list out, deletes allocated memory, exits
		else if (userInput == "5") {
			write_text_file(size, list);
			delete[]list;
			return 0;
		}
	}
}
//method that writes to file
void write_text_file( int &size,Employee *list) {
	ofstream out_file("C:/Users/Kevin Liu/source/repos/kxl173730Asg5/kxl173730Asg5/Employee.txt", std::ofstream::binary);

	if (!out_file.is_open())
		cout << "Cannot open file";
	else {
		for(int i=0;i<size;i++)
		out_file << list[i].getId()<<" "<<list[i].getFirstName()<<" "<<list[i].getLastName()<<" "<<list[i].getBirthDate()<<" "<<list[i].getGender()<<" "<<list[i].getStartDate()<<" "<<list[i].getSalary()<<endl;
		out_file.close();
	}
	
}
//method that reads from Employee.txt in the beginning and takes its info in if it exists
bool readFile(Employee *list, int &size) {
	string id;
	string firstName;
	string lastName;
	string birthDate;
	char gender;
	string startDate;
	double salary;
	ifstream input;
	string file = "Employee.txt";
	input.open(file.c_str());
	if (input) {
		while (input.good()) {
			input >> id >> firstName >> lastName >> birthDate >> gender >> startDate >> salary;
			Employee person (id,firstName,lastName,birthDate,gender,startDate,salary);
			list[size++] = person;
		}
		input.close();
		if (size > 101)
		{
			cout << "The number of employees exceeds 100" << endl;
			return false;
		}
		return true;
	}
	return false;
}

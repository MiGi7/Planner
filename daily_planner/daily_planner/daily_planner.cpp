// daily_planner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;



void checkedSaved() {
	const string file = "data_file.txt";
	ifstream ifile(file);
	if (!(bool)ifile) {
		ofstream file_;
		file_.open("data_file.txt");
		file_ << "This is saved data for the Planner" << endl;
		file_.close();
		cout << "Saved data created" << endl;
		return;
	}
	cout << "There is saved data present" << endl;
}

//prints the incomplete tasks refreshing the console
void printIncomp(Data data) {
	system("CLS");
	todoBar(data);
	printTasks(data, 'i');
}

//prints the complete tasks refreshing the console
void printComp(Data data) {
	system("CLS");
	todoBar(data);
	printTasks(data, 'c');
}


int main() {
	Data newData;
<<<<<<< HEAD
	newData.importData();
	int date_len = currentDate();
	printComp(newData);
	printIncomp(newData);
=======
	newData.addTaskIncom("Hello there GINA");
	newData.addTaskIncom("Its me GINA");
	newData.addTaskIncom("I love my girlfriend");
	newData.addTaskIncom("I need to shower");
	int date_len = currentDate();
	todoBar(newData);
	printTasks(newData);

>>>>>>> ed029d9e0d7465bbb21319178e6f95d50bd610c6
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

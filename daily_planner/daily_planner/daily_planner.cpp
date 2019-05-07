// daily_planner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;



void checkedSaved() {
	const string file = "data_file.txt";
	ifstream ifile(file);
	if (!(bool)ifile) {
		ofstream file_;
		file_.open("data_file.txt");
		file_ << "This is saved data for Planner" << endl;
		file_.close();
		cout << "Saved data created" << endl;
		return;
	}
	cout << "There is saved data present" << endl;
}


int main() {
	Data newData;
	newData.addTask("Gina");
	newData.addTask("poo");
	newData.addTask("Ginas");
	newData.movetoCom(0);
	newData.updateLen();
	newData.exportData();
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

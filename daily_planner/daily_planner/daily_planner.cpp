// daily_planner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

//prints the complete tasks refreshing the console
//prints the incomplete tasks refreshing the console
int printList(Data data, int state) {
	if (state == 1) {
		system("CLS");
		todoBar(data);
		printTasks(data, 'i');
		commandBar();
		return 1;
	}
	else if (state == 0) {
		system("CLS");
		todoBar(data);
		printTasks(data, 'c');
		commandBar();
		return 0;
	}
}

void commandSelection(Data data, int state) {
	std::string command;
	std::getline(std::cin, command);
	if (command == "add" || command == "Add") {
		std::string task;
		std::cout << "What is the name of your task?" << std::endl;
		std::getline(std::cin, task);
		data.addTaskIncom(task);
		printList(data, state);
		if (data.exportData()) {
			std::cout << std::endl;
			std::cout << "Tasks has successfully been moved!" << std::endl;
		}
		else {
			std::cout << std::endl;
			std::cout << "Something went wrong. Please try again." << std::endl;
		}
		commandSelection(data, state);
	}
	else if (command == "movetocomp" || command == "Movetocom") {
		int pos;
		std::cout << "What task would you like to move to the completed tasks (number)?" << std::endl;
		std::cin >> pos;
		data.movetoCom(pos);
		printList(data, state);
		if (data.exportData()) {
			std::cout << std::endl;
			std::cout << "Tasks has successfully been moved!" << std::endl;
		}
		else {
			std::cout << std::endl;
			std::cout << "Something went wrong. Please try again." << std::endl;
		}
		commandSelection(data, state);
	}
	else if (command == "delete" || command == "Delete") {
		int pos;
		std::cout << "What task would you like to delete (number)?" << std::endl;
		std::cin >> pos;
		std::string response;
		std::cout << "Are you sure you would like to delete this task (Yes or No)?" << std::endl;
		std::cin >> response;
		if (response == "y" || response == "Yes" || response == "yes") {
			data.deleteTask(pos);
			printList(data, state);
			if (data.exportData()) {
				std::cout << std::endl;
				std::cout << "Tasks has successfully been moved!" << std::endl;
			}
			else {
				std::cout << std::endl;
				std::cout << "Something went wrong. Please try again." << std::endl;
			}
			commandSelection(data, state);
		}
		else {
			std::cout << "Tasks has not been removed" << std::endl;
			printList(data, state);
			commandSelection(data, state);
		}
		if (data.exportData()) {
			std::cout << std::endl;
			std::cout << "Tasks has successfully been moved!" << std::endl;
		}
		else {
			std::cout << std::endl;
			std::cout << "Something went wrong. Please try again." << std::endl;
		}
	}
	else if (command == "Incomp" || command == "incomp" || command == "incom" || command == "Incom") {
		state = 1;
		printList(data, state);
		commandSelection(data, state);
	}
	else if (command == "comp" || command == "Comp" || command == "Com" || command == "com") {
		state = 0;
		printList(data, state);
		commandSelection(data, state);
	}
	else {
		std::cout << "the program is about to close" << std::endl;
		std::string response;
		if (response == "y" || response == "Yes" || response == "yes") {
			exit(0);
		}
		printList(data, state);
		commandSelection(data, state);
	}
}

int checkedSaved() {
	const string file = "data_file.txt";
	ifstream ifile(file);
	if (!(bool)ifile) {
		ofstream file_;
		file_.open("data_file.txt");
		file_ << "This is saved data for the Planner" << endl;
		file_.close();
		cout << "Saved data created" << endl;
		return 0;
	}
	cout << "There is saved data present" << endl;
	return 1;
}



int main() {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 700, 1000, TRUE);

	Data newData;
	if (checkedSaved()) {
		newData.importData();
	}
	printList(newData, 1);
	commandSelection(newData, 1);
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

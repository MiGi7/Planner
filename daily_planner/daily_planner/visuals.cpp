//This file contains the code that will generate the list of tasks to cmd
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include "pch.h"
#include "visuals.h"

// this file handles the visuals of the Planner

//prints out the time stamp but also returns the len of the time stamp
int currentDate() {
	DateTime date;
	int len = date.dateToString().length();
	char symbol = '*';
	for (int i = 0; i < len + 2; ++i) {
		std::cout << symbol;
	}
	std::cout << std::endl;
	std::cout << symbol << date.dateToString() << symbol << std::endl; 
	for (int i = 0; i < len + 2; ++i) {
		std::cout << symbol;
	}
	std::cout << std::endl;
	return len;
}

void todoBar(Data data) {
	char symbol = '*';
	int len = data.longest_Incom_Task;
	for (int i = 0; i < len + 19; ++i) {
		std::cout << symbol;
	}
	std::cout << std::endl;
	std::cout << symbol << symbol<< "TO-DO" << symbol;
	for (int i = 0; i < len - 3; ++i) {
		std::cout << symbol;
	}
	std::cout << "Creation Date" << symbol;
	std::cout << std::endl;
	for (int i = 0; i < len + 19; ++i) {
		std::cout << symbol;
	}
	std::cout << std::endl;
}

void printTasks(Data data, char selector) {
	char symbol = '*';
	std::vector<Task> list;
	int len;
	if (selector == 'i') {
		list = data.incomp_Tasks;
		len = data.longest_Incom_Task;
	}
	else if (selector == 'c') {
		list = data.comp_Tasks;
		len = data.longest_Com_Task;
	}
	int counter = 1;
	for (Task &element : list) {
		int len_task = element.len;
		std::string num = std::to_string(counter);
		num = num + ". ";
		std::cout << num << element.toDo;
		if (len - len_task > 0) {
			for (int i = 0; i < len - len_task; ++i) {
				std::cout << ' ';
			}
		}
		std::cout << ' ';
		std::cout << symbol;
		std::cout << ' ';
		std::cout << element.creationTime.timeStamp();
		std::cout << symbol;
		std::cout << std::endl;
		for (int i = 0; i < len + 27; ++i) {
			std::cout << symbol;
		}
		std::cout << std::endl;
		++counter;
	}
}

void commandBar() {
	std::cout << std::endl;
	std::cout << "The commands for this application are:" << std::endl;
	std::cout << "Add    MovetoComp    Delete    Change    Incomp    Comp    " <<std::endl;
	std::cout << std::endl;
	std::cout << "Please enter a command." << std::endl;
}



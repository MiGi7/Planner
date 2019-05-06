#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <vector>

#ifndef DateTime_H
#define DateTime_H
class DateTime {
	std::string month;
	int day;
	int year;
	int hour;
	int minute;
	int second;
public:
	DateTime();
	std::string getMonth(int num);
	std::string dateToString();
	std::string timeToString();
};
#endif

#ifndef Task_H
#define Task_H


class Task {
	std::string toDo;
	DateTime creationTime;
	bool finished;
public:
	Task(std::string task="");
	void printTaskName();
};

#endif Task_H

#ifndef Data_H
#define Data_H


class Data {
public:
	std::vector<Task>comp_Tasks;
	std::vector<Task>incomp_Tasks;
	int longest_Com_Task;
	int longest_Incom_Task;

	Data();
	void addTask(std::string todo);
	void movetoCom(int pos);
};

#endif Data_H
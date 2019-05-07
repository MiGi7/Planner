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
	std::string hour;
	std::string minute;
	std::string second;
	int length;
	int len;
public:
	DateTime();
	std::string getMonth(int num);
	std::string dateToString();
	std::string timeToString();
	std::string timeStamp();
};
#endif

#ifndef Task_H
#define Task_H


class Task {
public:
	std::string toDo;
	int len;
	DateTime creationTime;
	bool finished;
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
	void updateLen();
	void addTask(std::string todo);
	void movetoCom(int pos);
	int exportData();
};

#endif Data_H
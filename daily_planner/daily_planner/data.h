#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <vector>

#ifndef DateTime_H
#define DateTime_H
class DateTime {
public:
	std::string month;
	std::string day;
	std::string year;
	std::string hour;
	std::string minute;
	std::string second;
	int len;

	DateTime();

	DateTime(std::string str_time);
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
	Task(std::string task, DateTime dt);
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
	void addTaskIncom(std::string todo);
	void addTaskIncom(Task task);
	void addTaskCom(Task task);
	void movetoCom(int pos);
	int exportData();
	int importData();
};

#endif Data_H
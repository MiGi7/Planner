#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include "pch.h"
#include "data.h"
#include <vector>
#include <fstream>



//Current date and time
DateTime::DateTime(){
	time_t rawtime = time(0);
	tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	month = getMonth(timeinfo.tm_mon);
	day = timeinfo.tm_mday;
	year = timeinfo.tm_year + 1900;

	int unfiltered_hour = timeinfo.tm_hour;
	if (unfiltered_hour <= 9) {
		hour = "0" + std::to_string(unfiltered_hour);
	}
	else {
		hour = std::to_string(unfiltered_hour);
	}
	
	int unfiltered_minute = timeinfo.tm_min;

	if (unfiltered_minute <= 9) {
		minute = "0" + std::to_string(unfiltered_minute);
	}
	else {
		minute = std::to_string(unfiltered_minute);
	}

	int unfiltered_second = timeinfo.tm_sec;
	if (unfiltered_second <= 9) {
		second = "0" + std::to_string(unfiltered_second);
	}
	else {
		second = std::to_string(unfiltered_second);
	}
	
	std::string time_stamp = this->timeStamp();
	len = time_stamp.length();
}


//Given a integer, returns the respected month
std::string DateTime::getMonth(int num) {
	std::string month;
	switch (num + 1) {
	case 1: month = "January";
		break;
	case 2: month = "February";
		break;
	case 3: month = "March";
		break;
	case 4: month = "April";
		break;
	case 5: month = "May";
		break;
	case 6: month = "June";
		break;
	case 7: month = "July";
		break;
	case 8: month = "August";
		break;
	case 9: month = "September";
		break;
	case 10: month = "October";
		break;
	case 11: month = "November";
		break;
	case 12: month = "December";
		break;
	}
	return month;
}
	 
//returns the current day in the format MM-DD-YYYY
std::string DateTime::dateToString() {
	return month + " " + std::to_string(day) + " " + std::to_string(year);
}

//returns the current time in the format HH-MM-SS
std::string DateTime::timeToString() {
	return hour + ":" + minute + ":" + second;
}

std::string DateTime::timeStamp() {
	return this->dateToString() + " " + this->timeToString();
}




//Task class for creation and modification of Tasks
Task::Task(std::string task) {
		toDo = task;
		len = task.length();
		DateTime creationTime;
		finished = false;
}

void Task::printTaskName() {
	std::cout << toDo << std::endl;
}


//collection of all tasks and the longest tasks
Data::Data(){
	std::vector<Task>comp_Tasks;
	std::vector<Task>incomp_Tasks;
	int longest_Com_Task = 0;
	int longest_Incom_Task = 0;
}

//adds a task the incompleted tasks
void Data::addTask(std::string todo) {
	Task task(todo);
	int task_length = task.toDo.length();
	if (task_length > longest_Incom_Task) {
		longest_Incom_Task = task_length;
	}
	incomp_Tasks.insert(incomp_Tasks.begin(), task);
}


//move an incomplete task to the completed tasks. Updates the longest completed task.
void Data::movetoCom(int pos) {
	Task task = incomp_Tasks[pos];
	int task_length = task.toDo.length();
	if (task_length > longest_Com_Task) {
		longest_Com_Task = task_length;
	}
	comp_Tasks.push_back(task);
	incomp_Tasks.erase(incomp_Tasks.begin() + pos);
}

//Updates the length of the longest incomplete task
void Data::updateLen() {
	int max = 0;
	for (Task task : incomp_Tasks) {
		if (task.len > max) {
			max = task.len;
		}
	}
	longest_Incom_Task = max;
}

//exports the user data to a saved file 
int Data::exportData() {
	std::ofstream savedData;
	savedData.open("data_file.txt");
	for (Task task : comp_Tasks) {
		std::string task_name = task.toDo;
		std::string task_time = task.creationTime.timeStamp();
		savedData << "|" << task_name << ", " << task_time;
	}
	savedData << "|\n";
	savedData << longest_Com_Task << "\n";
	for (Task task : incomp_Tasks) {
		std::string task_name = task.toDo;
		std::string task_time = task.creationTime.timeStamp();
		savedData << "|" << task_name << ", " << task_time;
	}
	savedData << "|\n";
	savedData << longest_Incom_Task << "\n";
	savedData.close();
	return 0;
}


#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include "pch.h"
#include "data.h"
#include <vector>



//Current date and time
DateTime::DateTime(){
	time_t now = time(0);
	struct tm timeinfo {};
	month = getMonth(timeinfo.tm_mon);
	day = timeinfo.tm_mday;
	year = timeinfo.tm_year + 1900;
	hour = timeinfo.tm_hour;
	minute = timeinfo.tm_min;
	second = timeinfo.tm_sec;
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
	 
//prints the current day in the format MM-DD-YYYY
std::string DateTime::dateToString() {
	return month + " " + std::to_string(day) + " " + std::to_string(year);
}

std::string DateTime::timeToString() {
	return std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
}




//Task class for creation and modification of Tasks
Task::Task(std::string task) {
		toDo = task;
		DateTime creationTime;
		finished = false;
}

void Task::printTaskName() {
	std::cout << toDo << std::endl;
}


//Data class for hold together all task information
Data::Data(){
	//need to implement a vector array for a resizing function. Steps of 10. Need to free memory later 
	std::vector<Task>comp_Tasks;
	std::vector<Task>incomp_Tasks;
	int longest_Com_Task = 0;
	int longest_Incom_Task = 0;
}

void Data::addTask(std::string todo) {
	Task task(todo);
	incomp_Tasks.push_back(todo);
}
void Data::movetoCom(int pos) {
	//remember to pop the task from incomp_Tasks
	comp_Tasks.push_back(comp_Tasks[pos]);
}


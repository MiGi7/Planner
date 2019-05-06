#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include "pch.h"
#include "data.h"
#include <vector>

using namespace std;


//Current date and time of the Tasks created
class DateTime {
public:
	string month;
	int day;
	int year;
	int hour;
	int minute;
	int second;

	DateTime() { // default constructor 
		//creates a date object with the current date
		time_t now = time(0);
		struct tm timeinfo;
		month = getMonth(timeinfo.tm_mon);
		day = timeinfo.tm_mday;
		year = timeinfo.tm_year + 1900;
		hour = timeinfo.tm_hour;
		minute = timeinfo.tm_min;
		second = timeinfo.tm_sec;
	}

	//Given a integer, returns the respected month
	string getMonth(int num) {
		string month;
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
	string dateToString() {
		return month + " " + to_string(day) + " " + to_string(year);
	}
	string timeToString() {
		return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	}
};



//Task class for creation and modification of Tasks
class Task {
public:
	string toDo;
	DateTime creationTime;
	bool finished;

	Task(string task="") {
		toDo = task;
		creationTime = DateTime();
		finished = false;
	}

};


//Data class for hold together all task information
class Data {
	//need to implement a vector array for a resizing function. Steps of 10. Need to free memory later 
	vector<Task> comp_Tasks;
	vector<Task>incomp_Tasks;
	int longest_Com_Task;
	int longest_Incom_Task;
public:
	void addTask(Task task) {
		incomp_Tasks.push_back(task);
	}
	void movetoCom(int pos) {
		//remember to pop the task from incomp_Tasks
		comp_Tasks.push_back(comp_Tasks[pos]);
	}

};
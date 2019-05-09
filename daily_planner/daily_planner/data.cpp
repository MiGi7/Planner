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
	day = std::to_string(timeinfo.tm_mday);
	year = std::to_string(timeinfo.tm_year + 1900);

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


//converts a datestamp string into a DateTime object
DateTime::DateTime(std::string str_time) {
	len = str_time.length();
	int counter = 1;
	std::string line;
	for (char& letter : str_time) {
		if (letter == ' ') {
			if (counter == 1) {
				month = line;
			}
			else if (counter == 2) {
				day = line;
			}
			else if (counter == 3) {
				year = line;
			}
			line.clear();
			++counter;
			continue;
		}
		else if (letter == ':') {
			if (counter == 4) {
				hour = line;
			} else if (counter == 5) {
				minute = line;
			}
			line.clear();
			++counter;
			continue;
		}
		line.push_back(letter);
	}
	second = line;
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
	return month + " " + day + " " + year;
}

//returns the current time in the format HH-MM-SS
std::string DateTime::timeToString() {
	return hour + ":" + minute + ":" + second;
}

std::string DateTime::timeStamp() {
	return this->dateToString() + " " + this->timeToString();
}




//Task class for creation and modification of Tasks. Takes in a string as the todo and uses the current time.
Task::Task(std::string task) {
		toDo = task;
		len = task.length();
		DateTime creationTime;
		finished = false;
}

//Creates a Task using the string as the todo and using the DateTime object as the creationTime
Task::Task(std::string task, DateTime dt) {
	toDo = task;
	len = task.length();
	creationTime = DateTime(dt);
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
void Data::addTaskIncom(std::string todo) {
	Task task(todo);
	int task_length = task.toDo.length();
	if (task_length > longest_Incom_Task) {
		longest_Incom_Task = task_length;
	}
	incomp_Tasks.insert(incomp_Tasks.begin(), task);
}

void Data::addTaskIncom(Task task) {
	int task_length = task.toDo.length();
	if (task_length > longest_Incom_Task) {
		longest_Incom_Task = task_length;
	}
	incomp_Tasks.push_back(task);
}

void Data::addTaskCom(Task task) {
	int task_length = task.toDo.length();
	if (task_length > longest_Incom_Task) {
		longest_Com_Task = task_length;
	}
	comp_Tasks.push_back(task);
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
		savedData << "|" << task_name << "&" << task_time;
	}
	savedData << "|\n";
	savedData << longest_Com_Task << "\n";
	for (Task task : incomp_Tasks) {
		std::string task_name = task.toDo;
		std::string task_time = task.creationTime.timeStamp();
		savedData << "|"<< task_name << "&" << task_time;
	}
	savedData << "|\n";
	savedData << longest_Incom_Task << "\n";
	savedData.close();
	return 0;
}

//import the current data from the class to the text file
int Data::importData() {
	std::string com_tasks;
	std::string longest_com;
	std::string incom_tasks;
	std::string longest_incom;
	std::ifstream savedData;

	savedData.open("data_file.txt");
	std::getline(savedData, com_tasks);
	std::getline(savedData, longest_com);
	std::getline(savedData, incom_tasks);
	std::getline(savedData, longest_incom);
	//File is closed here 
	savedData.close();

	longest_Com_Task = std::stoi(longest_com);
	longest_Incom_Task = std::stoi(longest_incom);
	int type;
	std::string todo;
	std::string date;
	for (char& letter : com_tasks) {
		if (letter == '&') {
			date.clear();
			type = 0;
			continue;
		}
		else if (letter == '|') {
			if (todo != "") {
				Task task = Task(todo, DateTime(date));
				this->addTaskCom(task);
			}
			todo.clear();
			type = 1;
			continue;
		}
		if (type == 1) {
			todo.std::string::push_back(letter);
		}
		else if (type == 0) {
			date.std::string::push_back(letter);
		}
		else {
			std::cout << "ERROR" << std::endl;
			exit(1);
		}
	}
	for (char& letter : incom_tasks) {
		if (letter == '&') {
			date.clear();
			type = 0;
			continue;
		}
		else if (letter == '|') {
			if (todo != "") {
				Task task = Task(todo, DateTime(date));
				this->addTaskIncom(task);
			}
			todo.clear();
			type = 1;
			continue;
		}
		if (type == 1) {
			todo.std::string::push_back(letter);
		}
		else if (type == 0) {
			date.std::string::push_back(letter);
		}
		else {
			std::cout << "ERROR" << std::endl;
			exit(1);
		}
	}
	return 0;
}


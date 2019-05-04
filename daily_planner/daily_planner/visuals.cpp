//This file contains the code that will generate the list of tasks to cmd
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include "pch.h"
#include "visuals.h"

using namespace std;

//Given a integer, returns the respected month
string getMonth(int num) {
	string month;
	switch (num + 1){
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
string Date() {
	time_t now = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);
	return getMonth(timeinfo.tm_mon) + " " + to_string(timeinfo.tm_mday) + " "+ to_string(timeinfo.tm_year + 1900);
}




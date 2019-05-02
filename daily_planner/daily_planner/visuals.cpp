//This file contains the code that will generate the list of tasks to cmd
#include <iostream>
#include <ctime>
#include <string>
#include "pch.h"
using namespace std;

string getMonth(int num) {
	string month;
	switch (1){
		case 0: month = "January";
		case 1: month = "February";
		case 2: month = "March";
		case 3: month = "April";
		case 4: month = "May";
		case 5: month = "June";
		case 6: month = "July";
		case 7: month = "August";
		case 8: month = "September";
		case 9: month = "October";
		case 10: month = "November";
		case 11: month = "December";
		break;
	}
	return month;
}

void printDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << now->tm_mon << now->tm_mday << endl;
}


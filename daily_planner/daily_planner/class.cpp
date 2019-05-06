#include <iostream>
#include <string>
#include "pch.h"

using namespace std;

class Data {
	//need to implement a vector array for a resizing function. Steps of 10. Need to free memory later 
	string comp_tasks[100];
	string incomp_tasks[100];
	int time[100];
	
public:
	int longestTask() {
		int max_size = 0;
		for (string task : comp_tasks) {
			if (max_size < task.size()) {
				max_s
			 }
		}
	}

};
#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <vector>

using namespace std;
class DateTime {
	string month;
	int day;
	int year;
	int hour;
	int minute;
	int second;

	string getMonth(int num);
};

class Task {
	vector<string> toDo;
	DateTime creationTime;
	bool finished;
};

class Data {
	vector<Task> comp_Tasks;
	vector<Task>incomp_tasks;
	int longest_Com_Task;
	int longest_Incom_Task;
public:
	void addTask(Task task);
	void movetoCom(int pos);
};

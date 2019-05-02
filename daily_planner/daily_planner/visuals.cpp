//This file contains the code that will generate the list of tasks to cmd
#include <iostream>
#include <ctime>
using namespace std;

void main() {
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << (*now).tm_mon << endl;
}

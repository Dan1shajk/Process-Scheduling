#include <iostream>
#include <vector>

using namespace std;

class Process{

public:
	int burst;
	int id;
	vector<int> process_array;
	int io;
	int arrival_time;
	int index;
	int size;
	string pid;
	int rt;
	int wt;
	int tt;
	int at;

	Process();
	void insert(int x);
	int get_burst();
	int get_io();

};
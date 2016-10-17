#include "Header.h"

Process::Process()
{
	//cout << "in default constructor\n";
	process_array;
	io= 0;
	arrival_time = 0;
	index = 0;
	id = 0;
	size = 0;
	rt = 0; //first time it gets processed
	tt = 0;
	wt = 0;
	at = 0;
}

void Process::insert(int x)
{
	process_array.push_back(x);
}

int Process::get_burst()
{
	burst = process_array[index];

	return burst;
}

int Process::get_io()
{
	io = process_array[index];
	wt = wt + io;
	return io;
}

//Danish Shakil
//Z23055533
//CPU scheduler Programming assignment
//3/20/16

#include <iostream>
#include <vector>
#include "Header.h"
#include <string>
#include <iomanip>

using namespace std;

int find_min(vector<Process*> RQ);
void remove(int id, vector<Process*>* ap);
void print_rq(vector<Process*> *rq, int id);
int find_minat(vector <Process*> RQ);
void print_completed(vector <Process*> rq);



int main()
{
	int current_time = 0;
	int max = 0;
	double cpu_utilization = 0;
	cout << "Current Time: " << current_time << endl;

	vector<int> p1 = { 18, 41, 16, 52, 19, 31, 14, 33, 17, 43, 19, 66, 14, 39, 17 }; //create vectors of a process
	vector<int> p2 = { 8, 32, 7, 42, 6, 27, 17, 41, 7, 33, 11, 43, 12, 32, 14 };
	vector<int> p3 = { 6, 51, 5, 53, 6, 46, 9, 32, 11, 52, 4, 61, 8 };
	vector<int> p4 = { 25, 35, 19, 41, 21, 45, 18, 51, 12, 61, 24, 54, 23, 61, 21 };
	vector<int> p5 = { 15, 61, 16, 52, 15, 71, 13, 41, 15, 62, 14, 31, 14, 41, 13, 32, 15 };
	vector<int> p6 = { 6, 25, 5, 31, 6, 32, 5, 41, 4, 81, 8, 39, 11, 42, 5 };
	vector<int> p7 = { 16, 38, 17, 41, 15, 29, 14, 26, 9, 32, 5, 34, 8, 26, 6, 39, 5 };
	vector<int> p8 = { 5, 52, 4, 42, 6, 31, 7, 21, 4, 43, 5, 31, 7, 32, 6, 32, 7, 41, 4 };
	vector<int> p9 = { 11, 37, 12, 41, 6, 41, 4, 48, 6, 41, 5, 29, 4, 26, 5, 31, 3 };

	//==============================================================================================================//

	Process pro1;  //create objects for each process
	for (int i = 0; i < p1.size(); i++) //insert vector into the seperate objects
	{
		pro1.insert(p1[i]);
	}
	pro1.id = 1;
	pro1.pid = "P1";
	pro1.size = pro1.process_array.size();
	//==============================================================================================================//
	Process pro2;

	for (int i = 0; i < p2.size(); i++)
	{
		pro2.insert(p2[i]);
	}
	pro2.id = 2;
	pro2.pid = "P2";
	pro2.size = pro2.process_array.size();
	//==============================================================================================================//
	Process pro3;

	for (int i = 0; i < p3.size(); i++)
	{
		pro3.insert(p3[i]);
	}
	pro3.id = 3;
	pro3.pid = "P3";
	pro3.size = pro3.process_array.size();
	//==============================================================================================================//
	Process pro4;

	for (int i = 0; i < p4.size(); i++)
	{
		pro4.insert(p4[i]);
	}
	pro4.id = 4;
	pro4.pid = "P4";
	pro4.size = pro4.process_array.size();
	//==============================================================================================================//
	Process pro5;

	for (int i = 0; i < p5.size(); i++)
	{
		pro5.insert(p5[i]);
	}
	pro5.id = 5;
	pro5.pid = "P5";
	pro5.size = pro5.process_array.size();
	//==============================================================================================================//
	Process pro6;

	for (int i = 0; i < p6.size(); i++)
	{
		pro6.insert(p6[i]);
	}
	pro6.id = 6;
	pro6.pid = "P6";
	pro6.size = pro6.process_array.size();
	//==============================================================================================================//
	Process pro7;

	for (int i = 0; i < p7.size(); i++)
	{
		pro7.insert(p7[i]);
	}
	pro7.id = 7;
	pro7.pid = "P7";
	pro7.size = pro7.process_array.size();
	//==============================================================================================================//
	Process pro8;

	for (int i = 0; i < p8.size(); i++)
	{
		pro8.insert(p8[i]);
	}
	pro8.id = 8;
	pro8.pid = "P8";
	pro8.size = pro8.process_array.size();
	//==============================================================================================================//
	Process pro9;

	for (int i = 0; i < p9.size(); i++)
	{
		pro9.insert(p9[i]);
	}
	pro9.id = 9;
	pro9.pid = "P9";
	pro9.size = pro9.process_array.size();
	//==============================================================================================================//

	vector<Process*> all_processes;  //create a vector of processes
	vector<Process*> completed;

	all_processes.push_back(&pro1);   //fill up the process vector for the first time
	all_processes.push_back(&pro7);
	all_processes.push_back(&pro2);
	all_processes.push_back(&pro3);
	all_processes.push_back(&pro4);
	all_processes.push_back(&pro5);
	all_processes.push_back(&pro6);
	all_processes.push_back(&pro8);
	all_processes.push_back(&pro9);

	for (;;)
	{

		vector<Process*> ready_queue;
		int smallest_i = 0;

		for (int i = 0; i < all_processes.size(); i++) //go through 9 processes
		{
			if (all_processes[i]->arrival_time <= current_time) //check to see which processes are ready 
			{
				ready_queue.push_back(all_processes[i]);  //ones with the arrival time <= current time get entered into ready queue
			}

			if (i == all_processes.size() - 1)  //all the ready processes are entered 
			{
				if (all_processes.size() >= 1 && ready_queue.size() == 0) // in case if the arrival time for processes is greter then current time
				{
					int s = find_minat(all_processes); //find the next process which should be one with the smallest arrival time

					ready_queue.push_back(all_processes[s]);
					while (current_time != ready_queue[0]->arrival_time)
					{
						current_time++;  //increment current time untill the ready que arival time = current time
						cpu_utilization++;
					}
				}

				smallest_i = find_min(ready_queue); //goes through the ready queue, finds smallest process with the smallest burst
				cout << "Now Running: " << ready_queue[smallest_i]->pid << endl;

				if (ready_queue[smallest_i]->index == 0)  //to get the response time for each process
				{
					ready_queue[smallest_i]->rt = current_time;  
				}
				cout << "---------------------------------------------" << endl;
				current_time = current_time + ready_queue[smallest_i]->get_burst(); //current time gets added to the burst
	
				print_rq(&ready_queue, ready_queue[smallest_i]->id);

				if (completed.size() > 1)
				{
					print_completed(completed);
				}
				cout << "Current time: " << current_time << endl;




				if (ready_queue[smallest_i]->size < 2) //check to see if the process should be deleted because it has finished
				{
					ready_queue[smallest_i]->tt = current_time - ready_queue[smallest_i]->at; // to measure the turn around time
					completed.push_back(ready_queue[smallest_i]);
					remove(ready_queue[smallest_i]->id, &all_processes); //remove process
				}

				if (ready_queue[smallest_i]->size >= 2) //check to see if the process should be deleted because it has finished
				{
					ready_queue[smallest_i]->index++;
					ready_queue[smallest_i]->arrival_time = current_time + ready_queue[smallest_i]->get_io(); //updates the next arrival time for each process
					ready_queue[smallest_i]->index++;
					ready_queue[smallest_i]->size--;  // to know when the process will be ended
					ready_queue[smallest_i]->size--;

					if (ready_queue[smallest_i]->size == 0)
					{
						ready_queue[smallest_i]->tt = current_time - ready_queue[smallest_i]->tt; //turn around time
						completed.push_back(ready_queue[smallest_i]);
						remove(ready_queue[smallest_i]->id, &all_processes);
					}
				}
				//cout << "arival time for : " << ready_queue[smallest_i]->pid << " " << ready_queue[smallest_i]->arrival_time << endl;
			}

		}
		if (all_processes.size() == 0) //exit the loop if all processes are finished
		{
			break;
		}
	}

	
	double sumrt = pro1.rt + pro2.rt + pro3.rt + pro4.rt + pro5.rt + pro6.rt + pro7.rt + pro8.rt + pro9.rt;
	sumrt = sumrt / 9;										//average of response time

	double sumtt = pro1.tt + pro2.tt + pro3.tt + pro4.tt + pro5.tt + pro6.tt + pro7.tt + pro8.tt + pro9.tt;
	sumtt = sumtt / 9;  //average of turn around time 

	double sumwt = pro1.wt + pro2.wt + pro3.wt + pro4.wt + pro5.wt + pro6.wt + pro7.wt + pro8.wt + pro8.wt;
	sumwt = sumwt / 9;		//average of wait time

	cpu_utilization = (current_time - cpu_utilization) ;
	
	

	cpu_utilization = (cpu_utilization / current_time)*100;


	pro1.wt = pro1.arrival_time - pro1.wt;
	pro2.wt = pro2.arrival_time - pro2.wt;
	pro3.wt = pro3.arrival_time - pro3.wt;
	pro4.wt = pro4.arrival_time - pro4.wt;
	pro5.wt = pro5.arrival_time - pro5.wt;
	pro6.wt = pro6.arrival_time - pro6.wt;
	pro7.wt = pro7.arrival_time - pro7.wt;
	pro8.wt = pro8.arrival_time - pro8.wt;
	pro9.wt = pro9.arrival_time - pro9.wt;

	pro1.wt = pro1.tt - pro1.wt;
	pro2.wt = pro2.tt - pro2.wt;
	pro3.wt = pro3.tt - pro3.wt;
	pro4.wt = pro4.tt - pro4.wt;
	pro5.wt = pro5.tt - pro5.wt;
	pro6.wt = pro6.tt - pro6.wt;
	pro7.wt = pro7.tt - pro7.wt;
	pro8.wt = pro8.tt - pro8.wt;
	pro9.wt = pro9.tt - pro9.wt;

	

	
	
	cout << endl;
	
	cout << "P1 - Response Time : " << pro1.rt << "  Turnaround Time: " << pro1.tt << "  wait time " << pro1.wt << endl;
	cout << "P2 - Response Time : " << pro2.rt << "   Turnaround Time: " << pro2.tt << "  wait time " << pro2.wt << endl;
	cout << "P3 - Response Time : " << pro3.rt << "    Turnaround Time: " << pro3.tt << "  wait time " << pro3.wt << endl;
	cout << "P4 - Response Time : " << pro4.rt << "  Turnaround Time: " << pro4.tt << " wait time " << pro4.wt << endl;
	cout << "P5 - Response Time : " << pro5.rt << "   Turnaround Time: " << pro5.tt << "  wait time " << pro5.wt << endl;
	cout << "P6 - Response Time : " << pro6.rt << "   Turnaround Time: " << pro6.tt << "  wait time " << pro6.wt << endl;
	cout << "P7 - Response Time : " << pro7.rt << "   Turnaround Time: " << pro7.tt << "  wait time " << pro7.wt << endl;
	cout << "P8 - Response Time : " << pro8.rt << "    Turnaround Time: " << pro8.tt << "  wait time " << pro8.wt << endl;
	cout << "P9 - Response Time : " << pro9.rt << "   Turnaround Time: " << pro9.tt << "  wait time " << pro9.wt << endl;
	cout << endl;
	cout << "CPU utilization is : " << setprecision(5)<<cpu_utilization << "%" << endl;
	cout << "Avg response time is : " << sumrt << endl;
	cout << "Avg turnaround time is : " << sumtt << endl;
	cout << "Average wait time " << sumwt << endl;


	return 0;
}

int find_min(vector<Process*> RQ)
{
	Process* p = RQ[0];
	int smallest = 0;
	int min = RQ[0]->get_burst();
	int minat = RQ[0]->arrival_time;

	for (int i = 1; i < RQ.size(); i++)
	{
		if (RQ[i]->get_burst() < min)
		{
			min = RQ[i]->get_burst();
			minat = RQ[i]->arrival_time;
			p = RQ[i];
			smallest = i;
		}
	}

	return smallest;
}

int find_minat(vector <Process*> RQ)
{
	Process* p = RQ[0];
	int smallest = 0;
	int minat = RQ[0]->arrival_time;

	for (int i = 1; i < RQ.size(); i++)
	{
		if (RQ[i]->arrival_time < minat)
		{
			minat = RQ[i]->arrival_time;
			p = RQ[i];
			smallest = i;
		}
	}

	return smallest;
}
void remove(int id, vector <Process*>* pap)
{
	for (int i = 0; i < pap->size(); i++)
	{
		if (id == (*pap)[i]->id)
		{
			pap->erase(pap->begin() + i);
		}
	}
}


void print_rq(vector<Process*> *rq, int id)
{
	cout << "Ready Queue:	Process		Burst" << endl;
	for (int i = 0; i < rq->size(); i++)
	{
		//if ((*rq)[i]->id != id)
		{
			cout << "		" << (*rq)[i]->pid << "		" << (*rq)[i]->burst << endl;
		}

	}
	cout << "---------------------------------------------" << endl;
}

void print_completed(vector<Process*> rq)
{
	cout << ".........................\n\n";
	cout << "Completed : ";

	for (int i = 0; i < rq.size(); i++)
	{
			cout << rq[i]->pid << ", ";
	}
	cout << endl;
	cout << "..........................." << endl<<endl;
}
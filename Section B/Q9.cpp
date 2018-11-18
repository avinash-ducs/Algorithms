/********************************************
MCA 301 : Design and analysis of Algorithms
Assignment : 3
Promlem statement : 9

Submitted by:
	1. Avinash Prasad	07
	2. Sushmita Yadav	38
*********************************************/
#include<iostream>

using namespace std;

struct participant 
{
	int swim_time, bike_time, run_time, p_number;
};

void equate(participant &p1, participant &p2)
{
	/*
	Description
	-----------
	This function equates all fields of structure p1 to structure p2. It other words it a participant object to another participant object.
	
	Input variables
	---------------
	- p1 : object of type participant in which values have to be stored
	- p2 : object of type participant from which values have to be copied

	Return value
	------------
	NONE
	*/

	p1.p_number = p2.p_number;
	p1.swim_time = p2.swim_time;
	p1.bike_time = p2.bike_time;
	p1.run_time = p2.run_time;	
}

bool isGreater(participant p1, participant p2)
{
	/*
	Description
	-----------
	This function assumes that there are only two participant in the competition and 
	compares the completion_time(CT) of two scenarios possible
	1. CT1 : Participant 1 goes first = p1.swimtime + maximum(p1.remaintime, p2.swimtime + p2.remaintime)
	2. CT2 : Participant 2 goes first = p2.swimtime + maximum(p2.remaintime, p1.swimtime + p1.remaintime)
	
	where remaintime = biketime + runtime
	
	Input variables
	---------------
	- p1 : object of type participant for comparision
	- p2 : object of type participant for comparision
	- sr1 : expected swimming time of participant 1
	- br1 : expected bike time + running time of participant 1
	- sr2 : expected swimming time of participant 2
	- br2 : expected bike time + running time of participant 2

	Return value
	------------
	Returns 
	TRUE - ( CT1 > CT2 ) if completion time when participant 1 goes first is more than completion time when participant 2 goes first 
	FALSE -( CT1 <= CT2 ) otherwise
	*/

	int s1  = p1.swim_time;
	int br1 = p1.bike_time + p1.run_time;
	int s2  = p2.swim_time;
	int br2 = p2.bike_time + p2.run_time;
	if( s1 + max(br1, s2 + br2) > s2 + max(br2, s1 + br1))
		return true;
	else
		return false;
}

void sort(participant p[], int n)
{
	/*
	Description
	-----------
	This function performs insertion sort based on a special greater than operation.
	
	Input variables
	---------------
	- p[] : array of objects of type participant 
	- n : total number of participants
	- key : object of type participant

	Return value
	------------
	NONE
	*/
	
	int i,j;
	participant key;
	for(i=1; i<n; i++)
	{
		equate(key,p[i]);
		j=i-1;
		while(j>=0 && isGreater(p[j],key))
		{
			equate(p[j+1],p[j]);
			j=j-1;
		}
		equate(p[j+1], key);
	}
}

//driver function
int main()
{
	cout<<"\n\t\t\tCAMP COUNSELLOR PROBLEM\n\n";
	int n;
	while(true){
		cout<<"\nEnter number of participants : ";
		cin>>n;
		if(n>=1)
			break;
		cout<<"\nNumber of participants should be atleast 1!\n";
	}
	participant *p = new participant[n];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter expected swim-time, bike-time and run-time of participant "<<i+1<<": \n";
		cin>>p[i].swim_time>>p[i].bike_time>>p[i].run_time;
		p[i].p_number=i+1;
	}
	sort(p,n);
	cout<<"\n\nOrder of sending out participants is \n\n";
	for(int j=0; j<n; j++)
		cout<<p[j].p_number<<" ";
	return 0;
}

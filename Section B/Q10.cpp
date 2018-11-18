/********************************************
MCA 301 : Design and analysis of Algorithms
Assignment : 3
Promlem statement : 10

Submitted by:
	1. Avinash Prasad	07
	2. Sushmita Yadav	38
*********************************************/

#include<iostream>

using namespace std;

bool **adj_matrix;
bool *isPotential;

int countknown(int n, int person_x)
{
	/*
	Description
	-----------
	This function calculates number of people that a person_x knows.
	
	Input variables
	---------------
	- n : size of array isPotenital
	- person_x : person for which number of his/her acquaintance has to be calculated
	
	Global variable
	---------------
	- isPotenital : a boolean array, where value of isPotenital[i] states whether a person i can considered for invititation. True, if yes. False, if no.
	
	Return value
	------------
	number of people that person_x knows
	*/
	
	int count=0;
	for(int i=1; i<=n; i++){
		// test whether person i is a potenital invitee and also if person i and person_x know each other 
		if(isPotential[i] && adj_matrix[i][person_x])
			count++;
	}
	return count;
}	

void plan_party(int n){
	
	/*
	Description
	-----------
	This function computes all persons who can be invitated for a party out of n people based on following conditions:
		1. Every person invited should know at least five other people that are invited.
		2. Every person invited should not know at least five other people that are invited.
		3. Number of invitees is maximized
	
	Input variable
	--------------
	- n : Number of people to choose from
	
	Global variables
	----------------
	- adj_matrix : a boolean 2D matrix, where value at adj_matrix[x][y] states whether person x knows person y. True, if yes. False, if no.
	- isPotenital : a boolean array, where value at isPotenital[i] states whether a person i can considered for invititation. True, if yes. False, if no.

	Return value
	------------
	None
	
	Side effects
	------------
	If either condition 1 or condition 2 is not true for a person x then, update isPotenital[x] to false
	
	*/
	
	int potential_count = n;
	for(int j=1; j<=n; j++)
	{
			//stores the number of people j knows
			int known = countknown(n,j);
			//stores the number of people j does not know
			int unknown = potential_count - known - 1;
			
			//if a potenital invitee disqualifies any of condition 1 or 2, make him invalid and start checking from person 1 again
			if( isPotential[j] && (known < 5 || unknown < 5) )
			{
				isPotential[j]=false;
				potential_count--;
				j = 0;
				//if number of potenital invitee become less than 11, there is no way we can find a person who know 5 person and does not know 5 person
				if(potential_count < 11){
					for(int i=1;i<=n;i++)
						isPotential[i] = false;
					break;
				}
			}	
	}//the loop ends when every potential invitee satisfy both condition 1 and 2 or everyone become impotential
	
}

void print_invitees(int n){
	
	/*Description
	  -----------
	  This function print the final invitees and the count of invitees.
	*/ 
	int count = 0;
	cout<<"\n\nAlice can invite following people\n\n";
	for(int i=1; i<=n; i++){
		if(isPotential[i]){
			cout<<i<<"\t";
			count++;
		}
	}
	if(count == 0)
		cout<<"\n\nNo one can be invited.";
	else
		cout<<"\n\nMaximum number of people who can be invited is : "<<count;			
	
}
int main()
{
	int n;
	while(true){
		cout<<"\nEnter value of n(greater than or equal to 11): ";
		cin>>n;
		if(n>=11)
			break;
	}
	
	//dyanamic allocation
	adj_matrix = new bool*[n+1];
	for(int i=0;i<=n;i++)
		adj_matrix[i] = new bool[n+1];

	isPotential = new bool[n+1];
	
	//initialize adj_matrix such that nobody knows anyone
	for(int i=1; i<=n; i++)
	{
		isPotential[i] = true;
		for(int j=1; j<=n; j++)
		{
			adj_matrix[i][j] = false;
		}
	}
	
	char choice;
	
	//input pairs
	while(true) 
	{
		int x, y;
		cout<<"\nEnter pair (x,y) who know each other(person number starts from 1 and goes till n) \n";
		cout<<"\n Person x : ";
		cin>>x;
		if(x<1 || x>n){
			cout<<"\nInvald pair!Enter again!\n";
			continue;
		}
		cout<<"\n Person y : ";
		cin>>y;
		if(y<1 || y>n || y == x){
			cout<<"\nInvald pair!Enter again!\n";
			continue;
		}
		//update adjacency matrix
		adj_matrix[x][y] = true;
		adj_matrix[y][x] = true;
		cout<<"\nAre there any more pairs who know each other?(y/n): ";
		cin>>choice;
		if(choice=='n')
			break;
		x++; 
		y++;
	}
	plan_party(n);
	print_invitees(n);
	return 0;
}

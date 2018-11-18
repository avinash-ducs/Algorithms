/********************************************
MCA 301 : Design and analysis of Algorithms
Assignment : 3
Promlem statement : 6

Submitted by:
	1. Avinash Prasad	07
	2. Sushmita Yadav	38
*********************************************/

#include<iostream>
#include<math.h>

using namespace std; 

bool equivalenceTester(int a, int b)
{
	/*
	Description
	-----------
	This function tests whether two cards belong to same account.
	
	Input variables
	---------------
	- a : account number for card 1
	- b : account number for card 2

	Return value
	------------
	True, if both cards belong to same account.
	False, if both cards belong to different account.
	*/

	if(a==b) 
		return true;
	else
		return false;
}

int frequency(int card, int cards[], int n)
{
	/*
	Description
	-----------
	This function calculates the number of cards associated to same account as that of the card passed to this function.
	
	Input variables
	---------------
	- card : holds the account number of card to be tested.
	- cards : array of cards

	Return value
	------------
	returns the number of cards associated to same account as that of the card passed to this function.
	*/

	int count=0;
	for(int i=0; i<n; i++)
	{
		if(equivalenceTester(cards[i],card))
			count++;
	}
	return count;
}

int majority_card(int cards[], int n) 
{
	/*
	Description
	-----------
	This function returns the account which has more than n/2 cards asociated to it.
	
	Input variables
	---------------
	- cards : an array of account numbers of all cards.
	- n : total number of cards

	Return value
	------------
	account number of majority  card or -1 if there is no majority card	
	*/

	// if there is only one card, it is majority in itself
	if(n==1) 				
		return cards[0];
	int left_majority_freq;
	int right_majority_freq;
	int left_majority_card;
	int right_majority_card;
	int mid = floor(n/2);	
	int *left_subcards = new int[mid];
	int *right_subcards = new int[n - mid];

	for(int i = 0; i < mid; i++)
		left_subcards[i] = cards[i];
	int j = 0;
	for(int i = mid; i < n; i++)
		right_subcards[j++] = cards[i];
	
	//recursive calls
	left_majority_card = majority_card(left_subcards,mid);
	right_majority_card = majority_card(right_subcards,n-mid);
	
	if(equivalenceTester(left_majority_card, right_majority_card)) 
		return left_majority_card;
	
	left_majority_freq = frequency(left_majority_card, cards, n);
	right_majority_freq = frequency(right_majority_card, cards, n);

	if(left_majority_freq > mid) 
		return left_majority_card;
	if(right_majority_freq > mid) 
		return right_majority_card; 
	return -1;
}

//driver function
int main() 
{
	int *bankcards, N;
	cout<<"\t\t\tBANKCARDS PROBLEM\n\n";
	while(true){	
		cout<<"\nEnter number of cards: ";
		cin>>N;
		if(N>=1)
			break;
		cout<<"\nNumber of card should be atleast 1!";
	}

	bankcards = new int[N];
	
	for(int i=0; i<N; i++)	
	{	
		cout<<"\n\nEnter account number for card "<<i+1<<" : ";
		cin>>bankcards[i];
	}

	//test whether there is a majority card in given bankcards
	if(majority_card(bankcards, N) != -1)
		cout<<"\n\nThere is a majority card. \n";
	else		
		cout<<"\n\nThere is not any majority card. \n";	
	return 0;
}

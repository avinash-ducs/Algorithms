/********************************************
MCA 301 : Design and analysis of Algorithms
Assignment : 3
Promlem statement : 7

Submitted by:
	1. Avinash Prasad	07
	2. Sushmita Yadav	38
*********************************************/
#include<iostream>

using namespace std; 

struct transactionDates 
{
	int buy_day;
	int sell_day;
}t;

transactionDates calcDates(float p[], int n)
{
	/*
	Description
	-----------
	This function calculates the buy date and sell date for which profit is maximum.
	
	Input variables
	---------------
	- p[] : array of prices on each day
	- n : total number of days
	- min : stores minimum price of all the dates
	- max_diff : stores the maximum attainable profit by buying and selling on certain days
	- temp : used for storing temporary values calculated
	
	Return value
	------------
	If possible, returns an object of type transactionDates with the two dates for which profit is maximum.
	Else returns a tuple {-1,-1} indicating no such dates exist where profit can be made among given dates.
	*/

	float min=p[0];
	float max_diff=p[1]-p[0];
	int temp=0;
	if(max_diff>0)
		t.sell_day=1;
	for(int i=0; i<n; i++)
	{
		if((p[i]-min) > max_diff)	//compare current maximum difference with difference of each day's price with minimum
		{
			max_diff=p[i]-min;
			t.buy_day = temp;	//update minimum price day difference only if realistically possible(buy day < sell day)
			t.sell_day = i;		//save buy day and sell day with max price difference
		}	
		if(p[i]<min) 			//update min if a price less than current min price is encountered
		{
			min=p[i];
			temp=i;			//save day on which price is minimum in a temporary variable
		}
	}	
	if(max_diff<=0) { //if no such dates possible where profit can be made
		t.buy_day = -1;
		t.sell_day = -1;
	}					
	return t;				//return dates yielding max profit	
}		

//driver function
int main()
{
	int n;
	while(true){
		cout<<"\nEnter number of days: ";
		cin>>n;
		if(n>=2)
			break;
		cout<<"\nNumber of days should be atleast 2!\n";
	}
	//Input price
	float *p = new float[n];
	for(int i=0; i<n; i++)	
	{	
		cout<<"\nEnter price on day "<<i+1<<" : ";	
		cin>>p[i];
		if(p[i]<=0){
			cout<<"\nPrice cannot be negative or zero! Enter again!\n";
			i--;
		}
	}
	
	transactionDates max_profit_days = calcDates(p,n);
	
	if(max_profit_days.buy_day == -1)
		cout<<"\nNo way to make money during these days! ";
	else
		cout<<"\nBuy on day "<<max_profit_days.buy_day+1<<" and sell on day "<<max_profit_days.sell_day+1<<"\n";	
	return 0;
}

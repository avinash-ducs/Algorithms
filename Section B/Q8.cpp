/********************************************
MCA 301 : Design and analysis of Algorithms
Assignment : 3
Promlem statement : 8

Submitted by:
	1. Avinash Prasad	07
	2. Sushmita Yadav	38
*********************************************/

#include<iostream>
#include<math.h>
using namespace std;

struct license{
	//structure to store license no. along with rate of growth of its price
	int license_no;
	float rate_of_growth;
};

int find_max(license l_arr[], int n){
	
	/*
	Description
	-----------
	This function returns the license_no of software having maximum rate_of_growth value in l_arr.
	
	Input variables
	---------------
	- l_arr : array of objects of license type
	- n : number of objects in array l_arr
	
	Return value
	------------
	license number with maximum rate_of_growth
	
	Side effects
	------------
	Swaps the maximum object(based on rate_of_growth) of array l_arr with the first object
	*/

	//max stores the index of license with most expensive license growth rate in array l
	int max = 0;			

	//tranversing entire array to find most expensive license
	for(int i=1;i<n;i++){
		if(l_arr[i].rate_of_growth > l_arr[max].rate_of_growth)
			max = i;
	}
	
	//Now, max index has most expensive license in l_arr, so swap it with first license object of l_arr
	swap(l_arr[0].rate_of_growth, l_arr[max].rate_of_growth);
	swap(l_arr[0].license_no, l_arr[max].license_no);	
	
	//return the license of first license object in array l_arr
	return l_arr[0].license_no;	
}

void print_order(license l_arr[], int n){
	
	//This function finds and prints the order of buying license
	
	for(int i=0; i<n; i++){
		//call to find maximum from the remaining array l[i..n-1]
		cout<<"License "<<find_max((l_arr+i), n-i);
		cout<<"  : Rate "<<l_arr[i].rate_of_growth<<endl;
	}
}

float amount(license l_arr[], int n){

	/*
	Description
	-----------
	This function returns the total minimized amount to be spend to buy license 
	
	Input variables
	---------------
	- l_arr : array of objects of license type
	- n : number of objects in array l_arr

	Return value
	------------
	None
		
	Side effects
	------------
	Sorts l_arr in decreasing order of rate_of_growth and prints this sorted array.
	*/
	
	float amount  = 0;
	for(int i=0; i<n; i++){
		amount += pow(l_arr[i].rate_of_growth, i); 
	}
	return amount*100;
}
int main(){

	int n;
	cout<<"\t\t\tSOFTWARE LICENSE PROBLEM\n";
	
	while(true){
		cout<<"\n\nEnter number of cryptographic softwares : ";
		cin>>n;	
		if(n>=1)		//number of software must be atleast 1
			break;
		else
			cout<<"\nNo. of softwares should be atleast 1!";
	}
	license *l = new license[n];
	//input rate
	for(int i=0; i<n; i++){
		
		float temp;
		cout<<"\n\nEnter rate of growth for license "<<i+1<<" : ";
		cin>>temp;
		//test whether rate entered is greater than 1 or not
		if(temp <= 1){
			cout<<"\nrate must be greater than 1!";
			i--;
			continue;
		}
		l[i].license_no = i+1;
		l[i].rate_of_growth = temp;
	}
	
	cout<<"\n\nOrder of buying license is \n\n";
	print_order(l, n);

	cout<<"\n\nMinimized amount is : $"<<amount(l, n);
}

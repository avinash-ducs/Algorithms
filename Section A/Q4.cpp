#include<iostream> 
using namespace std; 

#define gap 5		//restriction of distance between two billboards

int calcMaxRevenue(int total_miles, int site[], int revenue[], int no_of_sites) 
{ 
	/*
	description: this function calculates max revenue corrosponding to sites given as input
	variables used: -> max_revenue-stores max revenue at each mile from 0 to total no of miles
			-> next-iterates through all sites
	return value: returns maximum revenue generated
	*/
	int *max_revenue = new int[total_miles+1]; 				
	for(int i=0;i<=total_miles;i++){
		max_revenue[i] = 0;
	}
	 
	int next = 0;
	if(site[0] == 0)
	{
		max_revenue[0] = revenue[0];
		next = 1;
	}
	
	for (int i = 1; i <= total_miles; i++) 
	{ 
		if (next < no_of_sites) 
		{ 
			if (site[next] != i) 						 
				max_revenue[i] = max_revenue[i-1];  
			else									
			{ 
				if (i <= gap) 					
					max_revenue[i] = max(max_revenue[i-1], revenue[next]); 
				else						
					max_revenue[i] = max(max_revenue[i-1], max_revenue[i-gap-1]+revenue[next]); 
				next++; 
			} 
		} 
		else
			max_revenue[i] = max_revenue[i - 1]; 
	} 

	return max_revenue[total_miles]; 
} 
 
int main() 
{
	/*
	description: driver program for the billboard problem
	variables used: -> total_miles-stores total number of miles from west to east
			-> site-stores all the sites
			-> revenue-stores revenue from each site
			-> count-total number of sites
	return value: returns 0 after successsful execution
	*/ 
	int total_miles;
	int *site = new int[total_miles];
	int *revenue = new int[total_miles];
	int count = 0;
	cout<<"\n\nEnter total number of miles from west to east: ";
	cin>>total_miles;
	while(true){
		cout<<"\nEnter sites( -1 to stop ): ";
		cin>>site[count++];
		
		//if site exceeds total miles 
		if(site[count - 1] > total_miles ){
			cout<<"Site cannot be beyond total miles! Re-enter... \n";
			count--;
			continue;
		}
		//if input is negative
		if(site[count - 1] < 0)
			break;
		//if sites are not in increasing order
		if( count>1 && site[count - 2] > site[count - 1] ){
			cout<<"New site cannot be smaller than previous site! Re-enter... \n";
			count--;
			continue;	
		}
	}
	count--;
	for(int i=0;i<count;i++){
		cout<<"\nEnter revenue for site "<<site[i]<<" : ";
		cin>>revenue[i];
		if(revenue[i]<=0){
			cout<<"Revenue has to be greater than zero! Re-enter... \n";
			i--;
			continue;
		}
	} 
	cout<<"\n\nMaximum revenue generated: "<<calcMaxRevenue(total_miles, site, revenue, count)<<"\n"; 
	return 0; 
} 


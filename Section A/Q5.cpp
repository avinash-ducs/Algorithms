#include<iostream>
#include<vector>
using namespace std;

bool isSubsequence(vector<string> s1, vector<string> s2)
{
	/*
	description: this function compares two sequences and finds if 1st is subsequence of 2nd
	variables used: i,j-used to traverse through s1 and s2
	return value: returns true if all events of s1 were found in s2 in same order else returns false
	*/	
	int j = 0;
	for(int i=0; i<s2.size() && j<s1.size(); i++){
		if(s1[j].compare(s2[i]) == 0)			
			j++;									
	}
	return (j==s1.size()); 
}

int main()
{
	/*
	description: driver function to find if one sequence is subsequence of other
	variables used: -> s1-stores the first sequence of events
			-> s2-stores the second sequence of events
			-> event-holds name of each event
	return value: returns 0 if program executed successfully
	*/	
	vector<string>	s1, s2;
	cout<<"\n\nEnter first sequence\n ";
	while(true){
		string event;
		cout<<"\nEnter next event( -1 to stop ): ";
		cin>>event;
		if(event.compare("-1") == 0)
			break;
		s1.push_back(event);
	}
	cout<<"\n\nEnter second sequence\n ";
	while(true){
		string event;
		cout<<"\nEnter next event( -1 to stop ): ";	
		cin>>event;
		if(event.compare("-1") == 0)
			break;
		s2.push_back(event);
	}
	
	if( isSubsequence(s1, s2))
		cout<<"\n\nSequence 1 is a subsequence of sequence 2.";
	else
		cout<<"\n\nSequence 1 is not a subsequence of sequence 2.";
		
	return 0;
}

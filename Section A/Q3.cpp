#include<iostream>

using namespace std;

bool queensafe(char **board, int n, int row, int col)
{
	/*
	description: this function checks if queen is safe at a given position or not
	variables used: -> i,j-used to traverse through the board
	return value: true if queen is safe at given position, else false
	*/
	int i,j;
	for(i=0; i<col; i++)
		if(board[row][i]=='Q')
			return false;
	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        	if (board[i][j]=='Q') 
            		return false;
	for (i=row, j=col; j>=0 && i<n; i++, j--) 
	        if (board[i][j]=='Q') 
	        	return false; 
  
	return true; 
} 

void printboard(char **board, int n)
{
	/*
	description: this function prints the current board
	variables used: -> i,j-used to traverse through the board
	return value: none
	*/
	cout<<"\n===========\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<board[i][j]<<"  ";
		cout<<"\n";
	}
}


bool nqueen(char **board, int n, int x)
{	
	/*
	description: this function creates a board combination where all n queens are safe
	variables used: -> i-used for traversal
	return value: returns true if combination is possible where all queens are safe, else returns false
	*/
	if(x==n)
	{
		printboard(board,n);
		return true;
	}
	bool a = false;
	if(x>=n)
		return true;
	for(int i=0; i<n; i++)
	{
		if(queensafe(board,n,i,x))
		{
			board[i][x]='Q';
			a=nqueen(board, n, x+1) || a;
			board[i][x]='-';
		}
	}
	return a;
}


int main()
{
	/*
	description: driver function for the n-queens problem
	variables used: -> n-stores value of number of queens
			-> board-holds queen positions on the board
	return value: returns 0 if program executes successfully
	*/
	int n;
	cout<<"\nEnter value of N: ";
	cin>>n;
	char **board = new char*[n];
	for(int i=0; i<n; i++)
		board[i] = new char[n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			board[i][j]='-';
	if(nqueen(board,n,0)==false)
	{
		cout<<"\nNo solution exists";
	}	
	delete board;
	return 0;
}

#include<iostream>
#include<limits.h>

using namespace std;

int main()
{
	/*
	description: driver function to calculate minimum matrix multiplications required to multipy n matrices
	variables used: -> num_matrix-number of matrices to be multiplied
			-> p-dimension array
			-> i-used for iterating
			-> ele-used to take dimension input
			-> matrix-holds value of multiplications required
	return value: returns 0 if program executes successfully
	*/
	int num_matrix, p[100], i, ele;
	cout<<"\nEnter 'dimension' array: (-1 to stop)\n";
	i=0;
	while(true)
	{
		cin>>ele;
		if(ele==-1)
			break;
		p[i++]=ele;
	}
	num_matrix=i-1;	
	int matrix[100][100];
	for(int i=1; i<=num_matrix; i++)
		matrix[i][i]=0;
	for(int l=2; l<=num_matrix; l++)
	{
		for(i=1; i<=num_matrix-l+1; i++)
		{	
			int j = i+l-1;
			matrix[i][j]=INT_MAX;
			for(int k=i; k<=j-1; k++)
			{
				int cost = matrix[i][k] + matrix[k+1][j] + p[i-1]*p[k]*p[j];
				if(cost < matrix[i][j])
				{
					matrix[i][j] = cost;
				}
			} 
		}
	}
	cout<<"\nRequired cost: "<<matrix[1][num_matrix]<<"\n";
	return 0;
}

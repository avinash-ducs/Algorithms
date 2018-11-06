#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

#define inf INT_MAX
const int graph_size = 5; 

struct node{
	/*
	description: this struct holds two integer values
	variables used: -> parent-holds value of parent of node
			-> distance-holds distance from the source
	return value: none
	*/
	int parent;
	int distance;
};

bool bellman_ford(int adj_matrix[][graph_size], int graph_size, int source){
	/*
	description: this function applies bellman ford algo and prints shortest path for input graph
	variables used: -> Q-array of nodes holding parent and distance from source for each vertex
			-> temp-temporary node used for initialization
			-> count-traverses through all nodes of graph
			-> u-holds index of minimum value node
			-> arr-array used to print shortest path
			-> v-used to keep track of parent
	return value: return true if solution exists else return false
	*/
	//initialization
	node* Q = new node[graph_size];
	node temp;
	int count = 0;
	while(count < graph_size){
		temp.parent = -1;	//parent null
		if(count == source)
			temp.distance = 0;	//distance=0, for source
		else
			temp.distance = inf;	//distance=inf for non-source vertices

		Q[count++]= temp;	
	}
	
	//Applying bellman-ford
	for(int k=1;k<=graph_size-1;k++){
		for(int u=0;u<graph_size;u++){
			for(int v=0;v<graph_size;v++){
				if(adj_matrix[u][v]!=0){
					if(Q[u].distance + adj_matrix[u][v] < Q[v].distance){
						Q[v].distance = Q[u].distance + adj_matrix[u][v];
						Q[v].parent = u; 
					}
				}
			}
		}
	}
	
	//determining negative-weight cycle from source
	for(int u=0;u<graph_size;u++){
			for(int v=0;v<graph_size;v++){
				if(adj_matrix[u][v]!=0){
					if(Q[v].distance > Q[u].distance + adj_matrix[u][v]){
						cout<<"\n\nNo solution exist!!";
						return false;
					}
				}
			}
	}
	
	//Displaying shortest path
	for(int i=0;i<graph_size;i++){
		if(i!=source){
			int arr[graph_size];
			int v = i;
			count = 0;
			while(v!=-1){
				arr[count++] = v + 1;
				v = Q[v].parent;
			}
			cout<<"\nShortest path from "<<source+1<<" to "<<i+1<<" is : ";
			count--;
			while(count>0){
				cout<<arr[count--]<<" ---> ";
			}		
			cout<<arr[count];
			cout<<"\nShortest distance from "<<source+1<<" to "<<i+1<<" is : "<<Q[i].distance<<"\n";
		}
	}
	return true;
}

int main(){
	/*
	description: driver function for bellman ford
	variables used: -> adj_matrix-stores adjacency matrix of input graph
			-> source-stores the source of graph
	return value: returns 0 if program executes successfully
	*/
	int adj_matrix[graph_size][graph_size] = { {0,6,0,7,0},
				 		   {0,0,5,8,-4},
						   {0,-2,0,0,0},
						   {0,0,-3,0,9},
						   {2,0,7,0,0}
			      			 };
	int source = 1;
	bellman_ford(adj_matrix, graph_size, source-1);
	return 0;
}

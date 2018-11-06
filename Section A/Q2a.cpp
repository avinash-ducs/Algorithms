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

bool all_visited(bool a[], int n){
	/*
	description: this function checks if all nodes of graph have been visited
	variables used: -> i-used for iteration
	return value: returns true if all nodes visited else false
	*/
	for(int i=0;i<n;i++)
		if(a[i] == false)
			return false;
	return true;
}

int extract_min(node Q[], bool visited[], int n)
{
	/*
	description: this function extracts minimum value node from all non-visited nodes
	variables used: -> c-used for traversal
			-> min_u-holds index of minimum value node
	return value: returns minimum value node 
	*/
	int c = 0;
	while(c <= n && visited[c++]);
	int min_u = c-1; 
	for(int i=0;i<graph_size;i++){
		if(!visited[i] && Q[i].distance < Q[min_u].distance){
			min_u = i;		
		}
	}
	return min_u;
}

void dijkstra(int adj_matrix[][graph_size], int graph_size, int source)
{
	/*
	description: this function applies dijkistra algo and prints shortest path for input graph
	variables used: -> Q-array of nodes holding parent and distance from source for each vertex
			-> temp-temporary node used for initialization
			-> count-traverses through all nodes of graph
			-> visited-boolean array storing visit status of each node
			-> u-holds index of minimum value node
			-> arr-array used to print shortest path
			-> v-used to keep track of parent
	return value: none
	*/
	//initialization
	node* Q = new node[graph_size];
	node temp;
	int count = 0;
	while(count < graph_size){
		temp.parent = -1;	// null parent
		if(count == source)
			temp.distance = 0;	// distance=0 for source
		else
			temp.distance = inf;	// distance=inf for all non-source nodes

		Q[count++]= temp;	
	}
	
	bool visited[graph_size];
	count = 0;
	//mark all nodes as not visited
	while(count < graph_size){
		visited[count++] = false;
	}	
	//apply dijkistra
	while(!all_visited(visited, graph_size)){
		int u = extract_min(Q,visited,graph_size);
		visited[u] = true;
		for(int i=0;i<graph_size;i++){
			if(adj_matrix[u][i] != 0){
				if(Q[u].distance + adj_matrix[u][i] < Q[i].distance){
					Q[i].distance = Q[u].distance + adj_matrix[u][i];
					Q[i].parent = u; 
				}
			}							
		}	
	}
	//print shortest path
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
}

int main()
{
	/*
	description: driver function for dijkistra
	variables used: -> adj_matrix-stores adjacency matrix of input graph
			-> source-stores the source of graph
	return value: returns 0 if program executes successfully
	*/
	int adj_matrix[graph_size][graph_size] = { {0,10,0,5,0},
				 		   {0,0,1,2,0},
						   {0,0,0,0,4},
						   {0,3,9,0,2},
						   {7,0,6,0,0}
			      			 };
	int source = 1;
	dijkstra(adj_matrix, graph_size, source-1);
	return 0;
}

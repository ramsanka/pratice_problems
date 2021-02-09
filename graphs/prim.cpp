#include <bits/stdc++.h> //What does this header file do ?

using namespace std;

#define V 5 // Vertices

//minkey functionality

//from the list of the selected keys, 
//Select the vertice which is not in MST tree
//&& is the smallest one. Returns the min_index
int minKey(int key[], bool mstSet[]) {

	int min = INT_MAX;
	int min_index ;


	for (int i = 0; i < V ; i ++) {
		if (mstSet[i] == false && key[i] < min){
			min_index = i;
			min = key[i];
		}
	}
	return min_index;
}


//print the mst
void printMST(int parent[], int graph[V][V]) {
	
	cout <<" Enter the PRIM MST" << endl;
	for (int i = 1; i< V; i++) {
		cout<<parent[i]<<"--"<<graph[i][parent[i]]<<""<<endl;
	}

	return;
}


//primMST
void primMST(int graph[V][V]) {

	int parent[V];
	int key[V];
	
	bool mset[V];

	
	//Init
	for (int i=0; i<V; i++) {
		key[i] = INT_MAX;
		mset[i] = false;
		parent[i] = 0;
	}


	key[0] = 0;
	mset[0] = true;

	parent[0] = -1;

	for (int count = 0; count < V-1; count ++) {
		
		//get the min key.
		int u = minKey(key, mset);

		mset[u] = true;

		for (int v = 0;  v < V; v ++) {
			
		    if (graph[u][v] && mset[v]==false && graph[u][v] < key[v]) {

			key[v] = graph[u][v];
			parent[v]=u;
		    }
		}

	}


	printMST(parent, graph);
	
	return;

}
			

int main() {

		
	int graph[V][V] = {{0,0,1,8,0},{1,0,3,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};		
	primMST(graph);


}


//Basic functionality of Union-find algorithm
//key for disjoint sets (data structure.
//Utility in kruskal algorithm


#include <bits/stdc++.h>
using namespace std;

//define a edge

class Edge {
	public:
		int src;
		int dest;
};

//define a graph

class Graph {
	public:
		int v;
		int e;
	        Edge *edge;
};


//Create a graph.

Graph* createGraph(int V, int E) {

	Graph *g = new Graph();
	g->v = V;
	g->e = E;

	g->edge = new Edge[g->e * sizeof(Edge)];

	return g;
}


//find utility
int find (int parent[], int i) {

	if (parent[i] == -1) 
		return i;
	return (find(parent, parent[i]));
}


//union
void union_find (int parent[], int x, int y) {
	parent[x] = y;
}


//Cycle.
int isCycle(Graph * g) {
	

	int *parent = new int[g->v * sizeof(int)];
	memset(parent, -1, sizeof(int) * g->v);
	

	//Parse through the edges and do the following
	//1. Check the parent.
	//2. If the parent are the different, unionize them
	//3. If the parent are the same, then declare the cycle.

	for (int i=0 ; i< g->e; i++) {
		
		int u = find(parent, g->edge[i].src);
		int v = find(parent, g->edge[i].dest);

		if (u == v)  //parents are the same the cycle is there.
		   return 1;

		//parent are not the same, hence we need unionize them.
		//since they are seperate sets, then we need to return
		//the indpendent indices of them.
		union_find(parent, u,v );

	}

	return 0;
}


int main() {

	//driver code.

	int V=3;
	int E=2;

	Graph *g = createGraph(V,E);

	g->edge[0].src = 0;
	g->edge[0].dest = 1;
	
	g->edge[1].src = 1;
	g->edge[1].dest = 2;

	//g->edge[2].src = 0;
	//g->edge[2].dest = 0;

	if (isCycle(g)) 
	   cout <<" There is a cycle "<<endl;
	else
	   cout <<" No cycle found" <<endl;

	return 0;
}


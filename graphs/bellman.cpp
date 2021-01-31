#include <bits/stdc++.h>

struct edge {
  int src;
  int dst;
  int wgt;
};


struct graph {
  int v;
  int e;

  struct edge *edge;  //array of edges.
		     //pointer. edge[] array of edges.
};


struct graph* create(int v, int e) {
 
   struct graph *g = new graph;
   g->v =  v;
   g->e =  e;
   g->edge =  new edge[e];
   
   return g;
}


void printgr (int dist[], int n) {

   printf("\nvertex distance from source\n ");
   for (int i =0; i < n; ++i) {
      printf("%d \t\t %d\n", i, dist[i]);
   }


}

//Bellman
void bellman(struct graph *g, int src) {
  
   int v = g->v;
   int e = g->e;

   int V = g->v;

   int dist[v];

   //set all the distances to infinity (-!)
   for(int i=0; i<v; i++)
	dist[i] = INT_MAX;

   dist[src] = 0;
   printf("\n starting point \n");
   printgr(dist,v);
   //Relax all edges
   //Outer loop iterates V-1 times (v vertices)
   //Inner loop iterates through all the edges

   for (int i = 1; i <= v-1 ; i++) {
      for (int j = 0; j < e; j++) {
	   
	  int u = g->edge[j].src;
          int v = g->edge[j].dst;

	  int w = g->edge[j].wgt;

	  //Relax
	  if (dist[u] != INT_MAX && (dist[u] + w < dist[v])) {
		dist[v] = dist[u] + w;
	  }
          printf("src-> %d and dst-> %d ",u,v);
	  printgr(dist,V);

     }
     //printgr(dist, v);
  }

 
 //negative cycle

 for(int i = 0; i < e;  i ++) {
     
	int u = g->edge[i].src;
        int v = g->edge[i].dst;

        int w = g->edge[i].wgt;

        if (dist[u] != INT_MAX && (dist[u] + w < dist[v])) {
	   printf("\n issue seen : negative cycle");
	   return;
	}
}

//print the array list.
printf("\nFinal bellman output\n");
printf("********************\n");
printgr(dist, v);

return;
	
}

	   
int main() {

	int v = 5;
	int e = 8;

	struct graph *g = create(v,e);

	g->edge[0].src = 0;
	g->edge[0].dst = 1;
	g->edge[0].wgt = -1;

        g->edge[1].src = 0;
        g->edge[1].dst = 2;
        g->edge[1].wgt = 4;


	g->edge[2].src = 1;
	g->edge[2].dst = 2;
	g->edge[2].wgt = 3;

	g->edge[3].src = 1;
	g->edge[3].dst = 3;
	g->edge[3].wgt = 2;


	g->edge[4].src = 1;
	g->edge[4].dst = 4;
	g->edge[4].wgt = 2;

	g->edge[5].src = 3;
	g->edge[5].dst = 2;
	g->edge[5].wgt = 5;

	g->edge[6].src = 3;
	g->edge[6].dst = 1;
	g->edge[6].wgt = 1;

	g->edge[7].src = 4;
	g->edge[7].dst = 3;
	g->edge[7].wgt = -3;


	//Run it baby
	bellman(g,0);

	return 0;
}





   







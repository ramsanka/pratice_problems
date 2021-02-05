#include <bits/stdc++.h>

struct edge {
   int src;
   int dst;
   int wgt;
};


struct graph {

    int v;
    int e;

    struct edge * edge;
};


struct graph  *create(int v, int e) {

     struct graph *g = new graph;
     g->v = v;
     g->e = e;
     g->edge = new edge[e];

     return g;
}


void printgr (int dist[], int n) {

     printf("new graph\n");
     for (int i=0; i < n; i++) {

	printf("%d dist %d\n",i,dist[i]);
     }

     return;
}

int mindist(int dist[], bool sptset[], int v) {

      int min = INT_MAX;
      int index;

      for (i=0; i<v; i++) {
           if (dist[i] < min) {
              index = i;
              min = dist[i];
	   }
       }

       return index;
}

//Dijkstra
void dijkstra(struct graph *g, int s) {
      

      int e = g->e;
      int v = g->v;

      int dist[v];
      bool sptset[v];

      //Set all the distances to infinity
      for (int i = 0; i < v; i++) {
        sptset[i] = false;
	dist[i] = INT_MAX;
      }
		
      //Set the distance of the source = 0	
      dist[s] = 0;

      //put the entry s in the queue and continue 
      //till the queue is not empty.

      for (int c=0; c <= v-1; c++) {
          //find the min distance of all the vertices.
	  int u = mindist(dist[], sptset[],v);

	  sptset[u] = true;

          //relaxation
          //vertices conected to u(directly), we need 
	  //to calculate the distance and update the dist.

	  
		
             
            if (!sptset[m] && g->edge[v]
          
      

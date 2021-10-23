#include <iostream>
#include <list>
//Euler
using namespace std;

class Graph {

  int v;
  list<int> *adj;

  public:
   
  void addEdge(int u, int w);
  int iseuler();
  bool isconnected();
  int dfsutil(int s, bool visited[]);
  Graph(int w);
};

Graph::Graph(int v) {

  this->v = v;
  adj = new list<int>[v];

}

void Graph::addEdge(int u, int w) {

  adj[u].push_back(w);
  adj[w].push_back(u);

}

int Graph::dfsutil(int s, bool visited[]) {

    visited[s] = true;

    list<int>::iterator i;
    for(i = adj[s].begin(); i != adj[s].end(); ++i) {
	if (!visited[*i]) {
           dfsutil(*i, visited);
        }
    }

 }



bool Graph::isconnected() {

     bool visited[v];

     int i;

     //init it first
     for(i =0; i < v; i++) 
         visited[i] = false;

     //identify a starting point
     for (int i = 0; i < v; i++)
        if (adj[i].size() != 0) 
          break;

     if (i == v) 
      {
         cout<<"we are done here, no edges here"<<endl;
         return false;
      }

  
    int r= dfsutil(i, visited);

    //iterate through the visited list.
    //if the visited is false and the edges are non-zero...
    //then it is a example of island

    for(int i = 0; i < v; i++) {

      if (visited[i] == false && adj[i].size() != 0) {
         cout<<"we have hit the islands (non connected parts) in the graph"<<endl;
         return false;
      }

    }

    return true;
}


int Graph::iseuler() {

      //first check if the graph is connected
      if (isconnected() == false) {
         return 0;
      }

      //check the number of vertices with odd edges
      int odd = 0;
      for (int i = 0; i < v; i++) {
	if (adj[i].size() & 1) {
             odd++;
        }
      }


      if (odd > 2)
        return 0;

      if (odd == 2) 
         cout<<"semi eulerian"<<endl;
      else if (odd == 0) {
         cout<<"eulerian"<<endl;
      }

     return odd;
}

void test(Graph &g) 
{ 
    int res = g.iseuler(); 
    if (res == 0) 
        cout << "graph is not Eulerian\n"; 
    else if (res == 1) 
        cout << "graph has a Euler path\n"; 
    else
        cout << "graph has a Euler cycle\n"; 
} 
  
// Driver program to test above function 
int main() 
{ 
    // Let us create and test graphs shown in above figures 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    test(g1); 
  
    Graph g2(5); 
    g2.addEdge(1, 0); 
    g2.addEdge(0, 2); 
    g2.addEdge(2, 1); 
    g2.addEdge(0, 3); 
    g2.addEdge(3, 4); 
    g2.addEdge(4, 0); 
    test(g2); 
  
    Graph g3(5); 
    g3.addEdge(1, 0); 
    g3.addEdge(0, 2); 
    g3.addEdge(2, 1); 
    g3.addEdge(0, 3); 
    g3.addEdge(3, 4); 
    g3.addEdge(1, 3); 
    test(g3); 
  
    // Let us create a graph with 3 vertices 
    // connected in the form of cycle 
    Graph g4(3); 
    g4.addEdge(0, 1); 
    g4.addEdge(1, 2); 
    g4.addEdge(2, 0); 
    test(g4); 
  
    // Let us create a graph with all veritces 
    // with zero degree 
    Graph g5(3); 
    test(g5); 
  
    return 0; 
}    
    
    
       
   

#include <iostream>
#include <list>


using namespace std;


class Graph {
    int v;
    list <int> *adj;
    void DFSUtil(int v, bool visited[]);
 
    public:
      Graph(int v);
      void addEdge(int v, int w);
      void BFS(int s);
      void DFS(int s);

};


Graph::Graph(int v) {

	this->v = v;
	adj = new list<int>[v];
}


void Graph::addEdge(int v, int w) {

	adj[v].push_back(w);
}


void Graph::DFSUtil(int v, bool visited[]) {

     visited[v] = true;
     cout<<v<<"->";

     list<int>::iterator i;
     for (i=adj[v].begin(); i != adj[v].end(); ++i) {
        if (visited[*i] != true) 
           {
           cout<<"\n the vertex visited"<<*i<<endl;
	   DFSUtil(*i, visited);
	  }
    }
     
}

void Graph::DFS(int s) {

    bool *visited = new bool[v];

    for (int i=0; i<v; i++) {
        visited[i] = false;
    }

    DFSUtil(s, visited);

    cout<<"end"<<endl;
}
       

void Graph::BFS(int s) {

    bool *visited = new bool[v]; //create a boolean array
    
    for (int i=0; i<v; i++) {   //set the boolean visited to false init
        visited[i] = false; 
    }

    list<int>queue;
    list<int>::iterator i;

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()) {

	s = queue.front();
	cout << s << "->";
	queue.pop_front();
	
	for (i=adj[s].begin(); i != adj[s].end(); ++i) {

	    if (visited[*i] != true) {
		visited[*i] = true;
		queue.push_back(*i);
	    }
        }

    }

    cout<<"end"<<endl;


    return;
}


int main () {

	Graph g(6);

	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
        g.addEdge(0,4);
        g.addEdge(2,5);

	cout<< "the program starts "<<endl;

	g.BFS(2);


	cout<<" the DFS program starts " << endl;
	g.DFS(0);

	return 0;
}	
		
	     
    


     
	

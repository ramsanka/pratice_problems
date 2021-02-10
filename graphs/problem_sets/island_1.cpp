#include <iostream>

using namespace std;


//This set contains the rank, parent
class DisJSet {

     int *rank;
     int *parent;
     int n;

     public:

	DisJSet(int n) 
        {

	rank  =  new int[n];
	parent=  new int[n];
	this->n = n;
	makeSet();

	}


	void makeSet()
	{
	  for (int i = 0; i < n; i++) {
		parent[i] = i;
	  }
        }


	int find(int x) 
	{

		if (parent[x] != x) {
		   parent[x] = find(parent[x]);
		}
		
		return parent[x];
	}

	void Union(int x, int y) {

		int xRoot = find(x);
		int yRoot = find(y);

		if (xRoot == yRoot) {
			return;
		}

	        if(rank[yRoot] < rank[xRoot]) {
			parent[yRoot] = parent[xRoot];
		}else if (rank[yRoot] > rank[xRoot]) {
			parent[xRoot] = parent[yRoot];
		}else {
			parent[yRoot] = parent[xRoot];
			rank[xRoot] = rank[xRoot] + 1;
		}

		}
	
	};

	

	int main() 
	{

		DisJSet obj(5);

		obj.Union(0,2);
		obj.Union(4,2);
		obj.Union(3,1);

		if (obj.find(4) == obj.find(0))
			cout <<"yes\n";
		else
			cout <<"no\n";
		if (obj.find(1) == obj.find(0))
			cout <<"yes\n";
		else		
			cout <<"no\n";
		
		return 0;
	}

		
		
		
			

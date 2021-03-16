//Dynamic programming.
//Min cost.
//DP-6
//travel in the following combinations.
//traverse down, right, daigonally lower.
//(m-1,n), (m,n-1),(m-1,n-1)


#include <bits/stdc++.h>

using namespace std;

#define R 3
#define C 3
#define MAX 100

int min(int x, int y, int z);

//Top down approach
//Base case
//recursion
//memoization
int minCost(int cost[R][C], int m, int n) {
    
	if (m < 0 || n < 0) 
	    return MAX;
	else if ( m == 0 && n == 0) 
	    return cost[0][0];
        else 
	     return cost[m][n] + min(minCost(cost, m-1,n-1),
				     minCost(cost, m-1,n),
				     minCost(cost, m, n-1));

}


int min( int x, int y, int z) {

	if (x < y)
	   return (x < z)?x:z;
        else
	   return (y < z)?y:z;
}


int main()
{
 
   int cost[R][C] = {{1,2,3},
		     {4,8,2},
		     {1,5,3}};

   cout << minCost(cost, 2,2) << endl;
  
   return 0;
}


    





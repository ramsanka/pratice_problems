//subset problem 
//dynamic problem.
//break it to subset (optimal/subproblems)
//Most recursion means it is a top down 
//approach till we hit the base case.
//exponential in nature

//Memoization --: how do we introduce this concept.
//Introduce a table. 2D array.
//
#include <stdio.h>
#include <bits/stdc++.h>

int tab[100][100];

bool isSubSet(int set[], int n, int sum) {

   //Base case
   if (sum == 0) 
	return true;

   if (n == 0)
	return false;

   //introduction of the table.
   if (tab[n-1][sum] != -1) {
	printf("table is in effect \n");
	return tab[n-1][sum];
   }

   //gaurd rail check
   /*
   if (sum < set[n-1]) 
      return isSubSet(set, n-1, sum);

   return (isSubSet(set, n-1, sum) || (isSubSet(set, n-1, sum-set[n-1])));
   */


   if (sum < set[n-1]) 
	return tab[n-1][sum] = isSubSet(set, n-1, sum);
   else 
	return tab[n-1][sum] = isSubSet(set, n-1, sum) ||
				 isSubSet(set, n-1, sum - set[n-1]);

}



//driver code;
int main() {
        //settig the tab to -1l

        memset(tab, -1, sizeof(tab));

	int set[] = {3,4,5,6,7,8};
        int sum = 12;

        int n = sizeof(set)/sizeof(set[0]);

        if (isSubSet(set, n, sum)) 
	    printf("subset found \n");
        else
	    printf("subset not found \n");

        return 0;
}

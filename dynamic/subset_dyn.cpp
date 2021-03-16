//subset problem 
//dynamic problem.
//break it to subset (optimal/subproblems)
//Most recursion means it is a top down 
//approach till we hit the base case.
//exponential in nature

//Recursion.
#include <stdio.h>
#include <bits/stdc++.h>

bool isSubSet(int set[], int n, int sum) {

   //Base case
   if (sum == 0) 
	return true;

   if (n == 0)
	return false;

   //gaurd rail check
   if (sum < set[n-1]) 
      return isSubSet(set, n-1, sum);

   return (isSubSet(set, n-1, sum) || (isSubSet(set, n-1, sum-set[n-1])));

}


//driver code;
int main() {

	int set[] = {3,4,5,6,7,8};
        int sum = 9;

        int n = sizeof(set)/sizeof(set[0]);

        if (isSubSet(set, n, sum)) 
	    printf("subset found \n");
        else
	    printf("subset not found \n");

        return 0;
}

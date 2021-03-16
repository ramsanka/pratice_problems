//basic code for dp starts
//example of top down approach + memoization (storing the entries)

#include  <bits/stdc++.h>

#define MAX 100

int dp[MAX];

int solve ( int n) {

    if (n < 0)
	return 0;

    if (n == 0)  //base case.
	return 1;
   
    if (dp[n] != -1)
	return dp[n];

    return (dp[n] =  solve(n-1) + solve(n-3) + solve(n-5));
}



    

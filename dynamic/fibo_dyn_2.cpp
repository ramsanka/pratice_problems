//fibo numbers
//thus is bottom up approach
//where the table is built up.
//Fibonacci numbers
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int f[100];

//fibo code.recursion
int fibo(int n) {

   //base case
   int i;


   f[0] = 0;
   f[1] = 1;

   for (i=2; i <=n; i++) 
	f[i] = f[i-1] + f[i-2];

   printf("\n the output of the fibo series %d",f[n]);

   return f[n];
}
   
      
//driver code
int main() {

    int i = 0;
    int result = 0;

    cout <<" enter the nth number of the fibo numbers" << endl;
    scanf ("%d", &i);

    result = fibo(i);

    printf("\n the %dth number  is %d",i, result);
    return 0;

}

//fibo numbers
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

//fibo code.recursion
int fibo(int n) {

   //base case

   if (n == 0) {
      return 0;
   }

   if (n ==  1) {
	return 1;
   }

   
   return fibo(n-1) + fibo(n-2);
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

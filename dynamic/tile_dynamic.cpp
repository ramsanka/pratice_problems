#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getnoways(int n) {

	if (n == 0)	
	   return 0;

        if (n == 1)
	   return 1;

        return getnoways(n-1) + getnoways(n-2);
}

//driver code.

int main() {
 
 int n = 4;
  
 int result;

 result = getnoways(n);

 printf("ways %d", result);


 return 0;
}

/* Greedy algorithm -: Activity selection */

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void activity(int s[], int f[], int n) {

  sort(f, f+n);
  
  int i,j;
  i = 0;
  
  cout<<" "<<i;

  for (int j=1; j<n; j++) {

     if (f[i] <= s[j]) {
        cout <<" "<<j;
	i = j;
     }
  }
}

//driver code
int main() {

   int s[] = {1,3,0,5,8,5};
   int f[] = {2,4,6,7,9,9};

   int n = sizeof(s)/sizeof(s[0]);
   
   activity(s,f,n);
   return 0;
}


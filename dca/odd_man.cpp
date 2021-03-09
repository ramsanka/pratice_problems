#include <iostream>
#include <stdio.h>

using namespace std;

int extra(int arr1[], int arr2[], int n) {
 

  //how to use binary tree to solve this problem ??

   int index = n;
   int left = 0;
   int right = n -1;


   while (left <= right ) {

      int mid = (left+right)/2;
      if (arr1[mid] == arr2[mid]) {
          left = mid+1;
      }else {

          index = mid;
          right = mid -1;
      }
   }


   return index;
}

   

//driver code.
int main() {

   int arr1[] = {2,4,6,10,12,13};
   int arr2[] = {2,4,6,10,13};

   int n  = sizeof(arr2)/sizeof(arr2[0]);


   cout <<"\n the extra element index"<< endl;
   int index = extra(arr1, arr2, n);
   cout << index;

   printf("\n the extra element is %d", arr1[index]);
   

   return 0;
}



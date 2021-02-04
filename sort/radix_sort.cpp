#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>

using namespace std;
#define RANGE  10


int getmax(int arr[], int n) {

  int i;
  int max = arr[0];
  for (i=0; i<n; i++) {
     if (arr[i]>= max)
       max = arr[i];
  }
  
  return max;
}
    
void count(int arr[], int n, int exp) {
   

     int len = n;
     int out[len];
     memset(out, 0, sizeof(out));     

     int count[RANGE]={0};
     
     int i;
     int mod=1;
     for (int m=1; m<exp; m++)
        mod = 10*mod;

     for(i = 0; i<n; ++i) {
        int index = (arr[i]/mod)%10;
        printf(" \n index %d", index);
        ++count[index];  
     }

     printf(" \n printing the frequency table \n");
     for(int j= 0; j < RANGE; ++j)
         printf("  %d " ,count[j]);

     
     cout<<endl;

     for (i=1; i<RANGE; ++i) {
        count[i] += count[i-1];
     }

     for(int j= 0; j < RANGE; ++j)
         printf("  %d " ,count[j]);


    //output array
     for(i = n-1; i>=0; i--) {
        out[count[(arr[i]/mod)%(10)]-1] = arr[i];
        count[(arr[i]/mod)%(10)] = count[(arr[i]/mod)%(10)]-1;
     }


     //put the sorted array
     printf("\n intermidatty array\n");
     for(i=0;  i < len; ++i) {
        arr[i] = out[i];
        printf(" %d ", arr[i]);
     }

}

   

int radixsort(int arr[], int len) {

    int m = getmax(arr,len);  
    int i=1;
    //number of times we need to sort the number.
    while (m >= 1) {
       int exp = i;
 
       count(arr, len, exp);
       m = m/10;
       i++;
    }
}


//Main code
int main() {

   int arr[] =  { 34, 45, 23, 2, 43, 4, 117 };

   int len = sizeof(arr)/sizeof(arr[0]);

   for (int i=0; i < len; i++) 
      printf("  %d  ", arr[i]);


   radixsort(arr, len);

   printf("\n sorted array \n");

   for (int i=0; i < len; i++)
      printf("  %d  ", arr[i]);

   return 0;
}


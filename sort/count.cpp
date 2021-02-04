#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>

using namespace std;

#define RANGE 10 

void countSort(int *arr, int size)
{
    int len = size;

    //output array

    int  out[len];

    //count array
    int count[RANGE+1];
    memset(count, 0, sizeof(count));

    int i;
    for (i =0; arr[i]; ++i) {
        ++count[arr[i]];
    }

    printf (" printing the frequency table\n");
    for (int j = 0; j < RANGE; ++j)
       printf(" %d ", count[j]);

    cout<<endl;

    for (i=1; i<=RANGE; ++i) {
        count[i] += count[i-1]; 
    }


    //output array
    for (i=0; arr[i] && i < RANGE; ++i) {
        out[count[arr[i]]-1] = arr[i];
        count[arr[i]] = count[arr[i]]-1;
    }
  
    //put the sorted array
    for(i = 0; arr[i] && i < RANGE; ++i) {
	arr[i] = out[i];
    }

  

}


//Main code

int main()
{
   
   int  arr[]= {1,5,4,4,7,3};
   
   //countSort(arr);

   int len = sizeof(arr)/sizeof(arr[0]);

   for (int i = 0; i < len; ++i) 
      printf(" %d ", arr[i]);

   cout<<endl;

   countSort(arr,len);

   for (int i = 0; i < len; i++) 
       printf(" %d ",arr[i]);

   cout<<endl;
 
   return 0;
}


 
 
     
    

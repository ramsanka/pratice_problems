//using the binary search for finding the occurences of the 
//digit in the sorted array[].

#include <bits/stdc++.h>
using namespace std;

int binaryhunt(int arr[], int left, int right, int x) {

   //base case of the binary search
   if (right < left) 
	return -1;

   int mid = left + (right - left)/2 ;

   if (arr[mid] == x) 
	return mid;

   if (arr[mid] > x) 
	return binaryhunt(arr, left, mid-1, x);
   else 
	return binaryhunt(arr, mid+1, right, x);

}
   

int count(int arr[], int n, int x) {


   int ind = binaryhunt(arr, 0, n -1, x);

   if (ind == -1)
	return 0;
 
   //found atlest first occurence of the element
   int count = 1;
   int left = ind -1;
    
   while (left >=0 && arr[left] == x) {
	count++; left--;
   }


   int right = ind + 1;
   while (right <= n && arr[right] == x) {
        count++; right++;
   }

   return count;
}


//driver code
int main() {

  int arr[] = { 1,2,2,2,2,3};
  int x = 2;
  int size = sizeof(arr)/sizeof(arr[0]);

  int cnt = count(arr,size,x);

  printf("the number of the occurences of %d", cnt);

  return 0;
}

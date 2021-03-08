#include <iostream>

using namespace std;
#define INT_MIN 0

int getMax(int arr[], int n) {

  int max = INT_MIN;
  for (int i = 0; i < n; i++) 
       if (arr[i] > max)
	   max = arr[i];
  return max;
}


int getSum (int arr[], int n) {

   int total = 0;

   for (int i = 0; i < n; i++) 
	total += arr[i];
   return total;
}


int numberofPainters(int arr[], int n, int maxLen) {   
  
     int total = 0;
     int painters = 1;

     for (int i = 0; i < n; i++) {
	total += arr[i];
    
        if (total > maxLen) {
            total = arr[i];
            painters++;
        }
     }

     return painters;

}


int partition (int arr[], int n, int k) {

   //how does this work
   //binary search to work this out.
   //we get the max and the min value which will provide the range.
 
   int min_val = getMax(arr, n);
   int max_val = getSum(arr, n);
 
   while (min_val < max_val) {

	int mid  = min_val + (max_val - min_val)/2;
        int pa_val = numberofPainters(arr, n, mid);

        //if the number of the painters are less => hours are high hence  reduce the number of hours.
        //if the number of the painters are more -> hours are low hence increas the number of hours.

        if ( pa_val <= k) {
	    max_val = mid;
        } else {
            min_val = mid + 1;
        }
   }
 
      return min_val;           
}

//driver code;
int main() {

  int arr[] = {1,2,3,4,5,6,7,8,9};
  int n = sizeof(arr)/sizeof(arr[0]);

  int k = 3;
  int final_output;
  

  final_output = partition(arr, n, k);
  cout << "final output "<< final_output << endl;
 
  return 0;
}  

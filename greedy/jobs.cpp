/* 
	Job sequencing with deadlines
	Greedy Method.
*/

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

//basic structure;
struct job {
 
    char id;
    int  dead;
    int  profit;
};

//comparison of the jobs
bool comparison (job a, job b) {

    return (a.profit > b.profit);
}

//main function.
//inputs it will take;
//array of the jobs. 
//size of the array

void printJob(job arr[], int n) {

  //sort the jobs.
  sort(arr, arr+n, comparison);

  int result[n];
 
  bool slot[n];

  //init the slot array
  for (int i = 0; i < n; i++) {
     slot[i] = false;
  }

  //dumping the array jobs.
  for (int i = 0; i < n; i++) {
      printf ("%d  ", arr[i].dead);
  }
  
  for (int i = 0; i < n; i++) {
       //start from the last possible slot.
       for (int j = min(n, arr[i].dead)-1; j>=0; j--) {

	   if (slot[j] == false) {
		
		result[j] = i;
		slot[j] = true;
		break;
	    }


	}
   }
   
        
   //dump the output.
   printf("\n the result is the following \n");
   for (int i = 0; i < n; i++) 
	if (slot[i]) 
	  cout<<arr[result[i]].id << " "; 
	   printf(" ");
   

}

//driver code.
int main() {

   job arr[] = {{'a',2,100}, {'b',1,19}, {'c',2,27},
		 {'d',1,25}, {'e',3,15}};

   int n = sizeof(arr)/sizeof(arr[0]);

   printf("the main code is getting dumped");
   
   printJob(arr, n);

   return 0;
}

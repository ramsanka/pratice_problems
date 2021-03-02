/* fractional knapsack */
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct item {
 
   int prof;
   int w;

   item(int prof, int w) {
     this->prof = prof;
     this->w    = w;
   }

};

bool comparison(struct item a, struct item b) {
 
     double ratio_a = a.prof/a.w;
     double  ratio_b = b.prof/b.w;

     return (ratio_a > ratio_b);
}

//array of inputs.
//number of input;
//total weight constraint
double knap_frac(struct item arr[], int n, int W) {

     sort(arr, arr+n, comparison);

     int curr_w = 0;
     double final_val = 0.0; //fractions may come to play.

     for (int i = 0; i < n; i++) {
          if (curr_w + arr[i].w <= W) {
              curr_w += arr[i].w;
	      final_val += arr[i].prof;
          } else {

              int remain = W - curr_w;
              final_val += arr[i].w * ((double)remain/(double)arr[i].w);
	      break;
	  }
     }


     return final_val;  
             
    
}


int main() {

    int W = 50;
    item array[] = {{50,10},{100,20},{140,30}};

    int n = sizeof(array)/sizeof(array[0]);

    cout << "maximum value is "<< knap_frac(array, n, W);
    return 0;
}
    

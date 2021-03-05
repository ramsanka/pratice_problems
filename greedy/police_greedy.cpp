#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int policethief(char arr[], int n, int k) {

     int res = 0;
     vector<int> thi;
     vector<int> pol;

     for(int i = 0; i < n; i++) {
        if (arr[i] == 'P') 
	   pol.push_back(i);
        else if (arr[i] == 'T') 
	   thi.push_back(i);
     }


     int l = 0;
     int r = 0;

     while ( l < thi.size() && r < pol.size()) {

         if (abs(thi[l] - pol[r]) <= k) {
		res++;
		l++;
		r++;
	 }

         else if (thi[l] < pol[r]) 
		l++;
	 else
		r++;
     }


     return res;
}


//driver code.
int main() {

     int k, n;

     char arr1[] = {'P','T','T','P','T','P'};
     k = 2;
     n = sizeof(arr1)/sizeof(arr1[0]);

     cout<<"max thieves caught "<<
	policethief(arr1, n, k) << endl;

     char arr2[] = {'P','T','P','T','P','T','P','T'};
     k = 3;
     n = sizeof(arr2)/sizeof(arr2[0]);
     
     cout<<"max thieves caught "<<
        policethief(arr2, n, k) << endl;

     return 0;
}

/* water connection problem
 * greedy.
 * GFG
 */

#include <bits/stdc++.h>
using namespace std;

#define INF 10000

//structure to retain the house info.
int n; //no.of houses.
int p; //no.of pipes.

int rd[100];
int wt[100];
int cd[100];

vector <int> a;
vector <int> b;
vector <int> c;

int ans;

int dfs(int w) {

   if (cd[w] == 0)
      return w;
   if (wt[w] < ans) 
      ans = wt[w];

   return dfs(cd[w]);

}

void solve(int arr[][3]) {

     int i = 0;
     while ( i < p) {
	
        int q = arr[i][0];
        int h = arr[i][1];
        int t = arr[i][2];

        cd[q] = h;
        wt[q] = t;
        rd[h] = q;

        i++;
     }


    a.clear();
    b.clear();
    c.clear();

    for (int j =1; j<=n; ++j) {

        if (rd[j] == 0 && cd[j]) {
            ans = INF;
            int w = dfs(j);

	    a.push_back(j);
            b.push_back(w);
            c.push_back(ans);
        }
    }
    cout<< a.size() <<endl;
        
    for (int j = 0; j < a.size(); ++j) 
	    cout<< a[j] << " " << b[j]
            << "  " << c[j] << endl;
     }
         

 
int main() {

    n = 9;
    p = 6;

   memset(rd, 0, sizeof(rd));
   memset(cd, 0, sizeof(cd));
   memset(wt, 0, sizeof(wt));


   int arr[][3] = { { 7,4,98},
		    { 5,9,72},
                    { 4,6,10},
                    { 2,8,22},
                    { 9,7,17},
                    { 3,1,66} };

   solve(arr);
   return 0;
}

//dynamic code.
//gold mine.

#include <bits/stdc++.h>

using namespace std;

#define MAX 4
int goldMax(int g[][MAX], int m, int n) {

 int gold[m][n];
 memset(gold, 0, sizeof(gold));

 for (int col = n-1; col >= 0; col--) {

     for(int row = 0; row < m; row++) {
	
	//right  condition
        int right = (col == n-1)? 0: gold[row][col+1];

        //right up
        int right_up  = (col == n-1 || row == 0)? 0: gold[row-1][col+1];


        //right_down
        int right_down = (row == m-1 || col == n-1)? 0: gold[row+1][col];

         
        printf("\nrow %d col %d", row, col);
        printf("\n gold right %d up %d down %d", right, right_up, right_down);

        gold[row][col] = g[row][col] + max(right, max(right_up, right_down));

        printf("\n the final gold[%d][%d] = %d",row,col, gold[row][col]);  
     }
  }


  int res = gold[0][0];

  for (int i =1; i < m; i++) 
	res = max(res, gold[i][0]);
  
  return res;
}



   

//driver code.
int main() {

 int gold_mine[4][4] = { {1,3,1,5},
			 {2,2,4,1},
                         {5,0,2,3},
                         {0,6,1,2}};


 int m = 4, n = 4;
 int result = goldMax(gold_mine, m, n);

 printf("\n the final output %d", result);

  return 0;
}



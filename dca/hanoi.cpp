#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, char from, char to, char aux) {

      if (n == 1) {

	cout <<"move disk 1 from rod"<< from << "rod" << to <<endl;
        return;
      }


      hanoi(n-1, from, aux, to);
      cout <<"move disk " << n << "from rod" << from << "to rod " << to << endl;
      hanoi(n-1, aux, to, from);
 }


int main() 
{
   int n = 4;
   hanoi(n, 'A','C','B');
   return 0;
}



      



/*egypt_fract*/

#include <iostream>
using namespace std;

void egypt_frac(int nr, int dr) {

  //validation check
  if (dr == 0 || nr == 0) 
    return ;

  if (dr%nr == 0)
  {
     cout<<"1/ "<<dr/nr;
     return;
  }

 
  if (nr%dr == 0) {
     cout << nr/dr;
     return;
  }


  if (nr > dr) 
  {    
    cout << nr/dr << " +";
    egypt_frac(nr%dr, dr);
    return;
  }

 
  //find the cieling
  int n = dr/nr + 1;

  cout << "1/" <<n << "+";

  egypt_frac((nr*n)-dr,dr*n);


}
  
 


//driver code.
int main() {
  
  int nr  = 6;
  int dr = 14;

  egypt_frac(nr, dr);


  return 0;

}




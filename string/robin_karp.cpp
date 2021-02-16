#include <bits/stdc++.h>

using namespace std;

#define d 256 //characters in the alphabet.

void find_patt(char txt[], char pat[]) {

   int N = strlen(txt);
   int M = strlen(pat);

   int p = 0;
   int t = 0;

   int q = 11; //To ensure that we do not overflow the integer capacity
   int h = 1;

   for (int i=0; i< M-1; i++) 
        h = (h*d)%q;              
  
   //calculate the hash function of the patt
   for (int j = 0; j < M ; j++) {
      p = (d * p + pat[j])%q; 
      t = (d * t + txt[j])%q;
   }

   int u = 0;
   //sliding function
   for (int i = 0; i <= N-M; i++) {
        if ( p == t) 
	{
		for (u = 0; u < M; u++) {
		   if (txt[i+u] != pat[u])
			break;
	        }
                           
       		if (u==M)
           	   printf("\n pattern found at index %d \n",i);
   	}


   	if ( i < N-M) 
   	{  

      		t = (d *(t - pat[i]*h) + txt[i+M])%q;
      		if (t<0) 
        		t = (t + q);
   	}
      printf("\n i %d p %d t %d",i,p,t);
   }
}

   



//driver code
int main() {

    char input[] = "AAAACCC";
    char patt[]  = "CCC";

    find_patt(input, patt);

}







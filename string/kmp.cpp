#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

//Build the lps table
void lps_arr(char *pat, int M, int *lps) 
{

    int len = 0;

    lps[0] = 0;
   
    int i = 1;
    while ( i < M) {

        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len == 0) {
                  lps[i] = 0;
                  i++;
            } else {
                  len = lps[len-1];
            }
        }

   }

   printf("\b the lps table \n");
   for (int i = 0; i < M; i++) {
      printf("   %d ",lps[i]);
   }

   printf("\n");
}

//kmp algo
void kmp(char *txt, char *pat) {

    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

    printf("size of the text %d\n",N);
    printf("size of the patt %d\n",M);

    lps_arr(pat, M, lps);

    int  i= 0;
    int  j = 0;

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        printf("\n j %d M %d", j,M);
        if (j == M) {
            printf("Pattern found at index %d", i-j);
            j = lps[j-1]; //reset;
        }


        else if (i < N && pat[j] != txt[i]) {

            if (j != 0) {
                j = lps[j-1];
	    } else {
                i = i+1;
            }
        }
     }
} 



//driver code
int main() {

  char txt[] = "AAAAABAAABA";
  char pat[] = "BCDEFBCEFB";

  kmp(txt, pat);

  return 0;
} 





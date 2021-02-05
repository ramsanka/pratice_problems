#include <iostream>
#include <stdio.h>
using namespace std;
void printArray(int arr[], int n);

void merge(int arr[], int l, int m, int r)
{


     cout<<"merge"<<endl;

     int n1 = m-l+1;
     int n2 = r-m;

     int L[n1];
     int R[n2];

     for (int i = 0; i < n1; i++) {
         L[i] = arr[l+i];
     }

     for (int i = 0; i< n2; i++) {
         R[i] = arr[m+1+i];
     }

     //Reset
     int i = 0;
     int j = 0;
     
     int k = l;

     //Merge the thing.
     while ( i < n1 && j < n2) {

       if (L[i]<=R[j]){
          arr[k] = L[i];
          i++;
       } else {
	  arr[k] = R[j];
          j++;
       } 

       k++;
     }

     while (i<n1) {
        arr[k] = L[i];
        i++;
        k++;
     }

     while (j<n2) {
       arr[k] = R[j];
       j++;
       k++;
     }

}

          
void mergeSort(int arr[], int l,  int r) {

    if (l>=r) {
     cout<<"l "<<l<<" r"<<r<<"returns"<<endl;
     return;
    }

    int m = (l+r-1)/2;

    cout<<"l= "<<l<<" r= "<<r<<" m= "<<m<<endl <<endl;

    mergeSort(arr, l, m);

    cout<<"1.l= "<<l<<" r= "<<r<<" m= "<<m<<endl;

    mergeSort(arr, m+1, r);

    printf( "after the call: l= %d m= %d r= %d\n",l,m,r);

    merge(arr,l,m,r);

}



void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<<endl;
}
 
// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}		


     

#include <bits/stdc++.h>

using namespace std;

int getMedian(int arr1[], int arr2[], int n) {
    
	int i = 0;
        int j = 0;

        int count;
        int m1 = -1; int m2 = 1;

        for (count  = 0; count <= n; count++) {


            if (i == n) {
		m1 = m2;
		m2 = arr2[0];
		break;
	    } else if (j == n) {
		m1 == m2;
		m2 = arr1[0];
		break;
	    }

            if (arr1[i] <= arr2[j]) {
		m1 = m2;
		m2 = arr1[i];
		i++;
	    } else {
		m1 = m2;
		m2 = arr2[j];	
		j++;
	    }
	}


       return (m1 + m2)/2;
}

//driver code
int main() {
		
	int arr1[] = {1,12,14,16,17};
	int arr2[] = {2,13,15,18,19};

	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);

        if(n1 == n2)  {
		cout<<"median is "<< getMedian(arr1, arr2, n1);
	} else {

		cout<<"uneqaul median"<<endl;
	}

}

      
       
    




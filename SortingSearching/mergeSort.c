#include <stdio.h>



void merge (int A[], int l, int m, int h) {
    int i = l,
    j = m+1,
    k = l;
    int B[h+1];
    while (i<=m && j<=h) {
        if (A[i]<A[j]) {
            B[k] = A[i];
            k++;
            i++;
        }
        else {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i<=m) {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j<=h) {
        B[k] = A[j];
        k++;
        j++;
    }

    for (i=l; i<=h; i++) {
        A[i] = B[i];
    }
}

void mergeSort (int A[], int l, int h) {
    
    if (l<h) {
    	int m = (l+h)/2;
        mergeSort (A,l,m);
        mergeSort (A,m+1,h);
        merge (A,l,m,h);
    }
}

int main () {
    int A [] = {1,6,8,4,6,9,15};
    mergeSort (A,0,6);
    int i;
    for (i = 0; i < 7; i++)
    {
        printf ("\t%d", A [i]);
    }
     
}
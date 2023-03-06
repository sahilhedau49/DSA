#include<stdio.h>

void insertionSort(int a[], int n);

int main()
{
    int a[] = {3,6,8,1,3,9,3,62,43};   // n=9
    insertionSort(a,9);

    for(int i=0;i<9;i++)
    printf("%d  ",a[i]);

    return 0;
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int key = a[i];
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[++j]=key;
    }
}
#include<stdio.h>

void selectionSort(int a[], int n);

int main()
{
    int a[] = {3,6,8,1,3,9,3,62,43};   // n=9
    selectionSort(a,9);

    for(int i=0;i<9;i++)
    printf("%d  ",a[i]);

    return 0;
}

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++)
    {
        int min_idx = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_idx])
            min_idx = j;
        }
        int temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
    }
}
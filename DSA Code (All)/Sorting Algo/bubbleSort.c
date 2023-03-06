#include<stdio.h>

void bubbleSort(int a[], int n);

int main()
{
    int a[] = {3,6,8,1,3,9,3,62,43};   // n=9
    bubbleSort(a,9);

    for(int i=0;i<9;i++)
    printf("%d  ",a[i]);

    return 0;
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        // int count = 0;
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                // count=1;
            }
        }
        // if(count = 0)
        //     break;
    }
}
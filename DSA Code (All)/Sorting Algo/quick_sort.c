#include<stdio.h>

void quickSort(int a[], int l, int h);
int partition(int a[], int l, int h);
void swap(int a[], int i, int j);

int main()
{
    int a[] = {9,5,6,3,1};
    quickSort(a,0,4);
    for(int i=0;i<5;i++){
        printf("%d  ",a[i]);
    }

    return 0;
}

void quickSort(int a[], int l, int h)
{
    if(l<h){
        int pivot = partition(a,l,h);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,h);
    }
}

int partition(int a[], int l, int h)
{
    int i = l;
    int j = h;
    int p = a[l];   // pivot element
    while(i<j){
        while(a[i]<=p){i++;}
        while(a[j]>p){j--;}
        if(i<j){swap(a,i,j);}
    }
    swap(a,l,j);
    return j;
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
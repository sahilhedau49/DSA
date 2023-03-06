#include<stdio.h>

int getInput();
int addNum(int a[], int l);
int printArray(int a[], int l);
int getNum();

int main()
{
    printf("Enter total length of array: ");
    int n = getInput();
    printf("Enter number of elements present in array: ");
    int l = getInput();

    if(l<n)
    {
        int a[n];
        printf("Enter array elements: ");
        for(int i=0;i<l;i++)
        scanf(" %d",&a[i]);

        addNum(a,l);
    }
    else
    printf("Increase length of array.\n");

    return 0;
}

int getInput()
{
    int a;
    scanf("%d",&a);
    return a;
}

int getNum()
{
    int x;
    printf("Enter element to be added in end of array: ");
    scanf("%d",&x);
    return x;
}

int printArray(int a[], int l)
{
    printf("Updated array --> ");
    for(int i=0;i<l+1;i++)
    printf("%d ",a[i]);
}

int addNum(int a[], int l)
{
    int num = getNum();
    a[l] = num;
    printArray(a,l);
}
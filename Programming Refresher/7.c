#include<stdio.h>

int getInput();
int cube(int x);
int sqr(int x);
int printArray(int a[], int n);
int solve(int a[], int n);


int main()
{
    int n = getInput();
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    scanf(" %d",&a[i]);
    
    solve(a,n);
    return 0;
}

int solve(int a[], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        a[i] = cube(a[i]);
        else
        a[i] = sqr(a[i]);
    }

    printArray(a,n);
}

int getInput()
{
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    return n;
}

int cube(int x)
{
    return x*x*x;
}

int sqr(int x)
{
    return x*x;
}

int printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
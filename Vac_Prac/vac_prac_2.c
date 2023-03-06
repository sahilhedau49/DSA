/*
    You are given with a series of buildings that have windows facing west. The buildings are in a straight line, and any building which is to the east of 
    a building of equal or greater height cannot view the sunset. Design an algorithm that processes buildings in east-to-west order and returns the set of 
    buildings which view the sunset. Each building is specified by its height.
*/

#include<stdio.h>

void initialize(int arr[],int n);
void can_see_sunset(int a[], int b[], int n);
int find_max(int a[], int i);
int max_index(int a[], int max, int i);

int main()
{
    int n,i;     // number of buildings
    printf("Enter number of buildings: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter heigths of buildings from west to east: \n* (sunset)  ");
    for(i=0;i<n;i++)
    scanf(" %d",&a[i]);

    int b[n];
    initialize(b,n);
    can_see_sunset(a,b,n);

    i=0;
    printf("Buildings with following heights can see sunset:  ");
    while(b[i] != 0)
    {
        printf("%d  ",b[i]);
        i++;
    }

    return 0;
}

void initialize(int arr[],int n)
{
    for(int i=0;i<n;i++)
    arr[i] = 0;
}

void can_see_sunset(int a[], int b[], int n)
{
    int i=n,j=0;
    while(i!=0)
    {
        int max = find_max(a,i);
        i = max_index(a,max,i);
        b[j] = max;
        j++;
    }
}

int find_max(int a[], int i)
{
    int max = 0;
    for(int k=0;k<i;k++)
    {
        if(a[k] > max)
        max = a[k];
    }
    return max;
}

int max_index(int a[], int max, int i)
{
    for(int k=i-1;k>=0;k--)
    {
        if(a[k] == max)
        return k;
    }
}
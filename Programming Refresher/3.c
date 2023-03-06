#include<stdio.h>

int getInput();
int printTable(int a, int b);

int main()
{
    int no,limit;
    printf("Enter number and its limit: ");

    no = getInput();
    limit = getInput();

    printTable(no, limit);

    return 0;
}

int getInput()
{
    int a;
    scanf("%d",&a);
    return a;
}

int printTable(int a, int b)
{
    int i;
    for(i=1;i<=b;i++)
    {
        printf("%d * %d = %d\n",a,i,a*i);
    }
    return 0;
}
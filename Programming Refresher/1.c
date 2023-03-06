#include<stdio.h>

int getInput();
int power(int x, int y);

int main()
{
    int x,y;
    printf("Enter any two numbers: ");
    x=getInput();
    y=getInput();
    int ans = power(x,y);
    printf("%d",ans);

    return 0;
}

int getInput()
{
    int a;
    scanf("%d",&a);
    return a;
}

int power(int x, int y)
{
    int p=1,i;
    for(i=0;i<y;i++)
    p = p*x;
    return p;
}
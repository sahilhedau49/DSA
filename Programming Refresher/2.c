#include <stdio.h>

int getInput();
int greatest(int a,int b,int c);
int findMax(int a, int b, int c);

int main()
{
    int a,b,c;
    printf("Enter any three numbers: ");
    
    a=getInput();
    b=getInput();
    c=getInput();
    
    findMax(a,b,c);

    return 0;
}

int getInput()
{
    int a;
    scanf("%d",&a);
    return a;
}

int greatest(int a,int b,int c)
{
    int grt = (a>b)?((a>c)?a:c):((b>c)?b:c);
    return grt;
}

int findMax(int a, int b, int c)
{
    int grt = greatest(a,b,c);
    
    if(a==grt && b!=grt && c!=grt)
    printf("A is greatest.\n");
    else if(a!=grt && b==grt && c!=grt)
    printf("B is greatest.\n");
    else if (a!=grt && b!=grt && c==grt)
    printf("C is greater.\n");
    else if(a==grt && b==grt && c!=grt)
    printf("A and B is greater.\n");
    else if(a!=grt && b==grt && c==grt)
    printf("B and C is greater.\n");
    else if(a==grt && b!=grt && c==grt)
    printf("A and C is greater.\n");
    else if(a==grt && b==grt && c==grt)
    printf("A, B and C is greater.\n");
    
    return 0;
}
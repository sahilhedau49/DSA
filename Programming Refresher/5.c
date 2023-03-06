#include<stdio.h>

int getInput();
int getSum(int n);

int main()
{
    int n = getInput();
    int sum = getSum(n);
    printf("Sum of digits of %d is %d.",n,sum);

    return 0;
}

int getInput()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    return n;
}

int getSum(int n)
{
    int sum=0,rem;

    while(n!=0)
    {
        rem = n%10;
        sum = sum + rem;
        n/=10;
    }

    return sum;
}
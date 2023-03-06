#include<stdio.h>
#include<math.h>

int getInput();
float intoRad(int t);
float findSin(int t);

int main()
{
    int t = getInput();
    findSin(t);

    return 0;
}

int getInput()
{
    int t;
    printf("Enter angle (in Degree): ");
    scanf("%d",&t);
    return t;
}

float intoRad(int t)
{
    float rad = t*0.0174533;
    return rad;
}

float findSin(int t)
{
    float rad = intoRad(t);
    float ans = sin(rad);
    printf("Sin(%d) = %.4f",t,ans);
}
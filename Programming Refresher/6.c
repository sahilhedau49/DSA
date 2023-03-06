#include<stdio.h>
#include<string.h>

int addString(char num1[], char num2[]);

int main()
{
    char num1[] = "1234";
    char num2[] = "2148";
    
    addString(num1,num2);

    return 0;
}

int addString(char num1[], char num2[])
{
    int n1=strlen(num1)-1;
    int n2=strlen(num2)-1;
    int c=0,i=0;                // c is for carry.
    char num[20];

    while(n1>=0 || n2>=0)
    {
        if(n1<0)
        {
            num[i] = (num2[n2]-48+c)%10+48; 
            c=(num2[n2]-48+c)/10;
            i++;
            n2--;
        }
        else if(n2<0)
        {
            num[i] = (num1[n1]-48+c)%10+48;
            c=(num2[n2]-48+c)/10;
            i++;
            n1--;
        }
        else
        {
            num[i] = (((num1[n1]-48)+(num2[n2]-48)+c)%10)+48;
            c=((num1[n1]-48)+(num2[n2]-48)+c)/10;
            n1--;
            n2--;
            i++;
        }
    }

    while(i>=0)
    {
        printf("%c",num[i-1]);
        i--;
    }
}
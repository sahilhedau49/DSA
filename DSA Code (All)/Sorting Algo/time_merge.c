#include <stdio.h>
#include<time.h>
#include"merge_sort.c"
#define MAX_SIZE 1000
int main(){
int n,i,step=10;
int a[MAX_SIZE];
double duration;
clock_t start,end; //typedef of a numeric type: represent running time

printf("n time \n");
for(n=0;n<=10000;n+=step)
{
    for(i=0;i<n;i++){
        a[i]=n-i;
    }
    start = clock(); //returns processor clock time since the program is started
    merge_Sort(a,0,n-1);
    end=clock();
    duration=(((double)(end-start))/CLOCKS_PER_SEC); //no. of clock ticks per second
    printf("%d %lf\n",n,duration);
    if(n==100)
    step=100;
    if(n==1000)
    step=1000;
}
return 0;
}
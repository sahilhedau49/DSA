#include <stdio.h>
#define mr 10
#define mc 10

struct matrix{
    int a[mr][mc];
    int r,c;
};

void createMatrix(struct matrix * m);
void displayMatrix(struct matrix m);

int main(){

    struct matrix m1, m2, sum, mul;

    createMatrix(&m1);
    createMatrix(&m2);
    displayMatrix(m1);

    return 0;
}

void createMatrix(struct matrix * m){
    printf("Enter no. of row and columns in matrix resp.: ");
    scanf("%d %d",&(m->r),&(m->c));
    printf("Enter matrix elements:\n ");
    for(int i=0;i<(m->r);i++)
    {
        for(int j=0;j<(m->c);j++)
        {
            scanf(" %d",&(m->a[i][j]));
        }
    }
}

void displayMatrix(struct matrix m)
{
    printf("\nMatrix is: \n");
    for(int i=0;i<(m.r);i++)
    {
        for(int j=0;j<(m.c);j++)
        {
            printf("%d ",(m.a[i][j]));
        }
    }
}
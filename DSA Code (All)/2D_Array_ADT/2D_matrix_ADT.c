#include <stdio.h>
#define MRow 10
#define MColumn 10

struct matrix{
    int a[MRow][MColumn];
    int r,c;
};

void create(struct matrix * m);
void display(struct matrix m);
void addition(struct matrix *sum, struct matrix *m1, struct matrix *m2);
void multiply(struct matrix *mul, struct matrix *m1, struct matrix *m2);
void transpose(struct matrix *trans1, struct matrix *m1);
void displayrm(struct matrix m);
void displaycm(struct matrix m);

int main()
{
    struct matrix m1, m2, sum, mul, trans1;
    create(&m1);
    create(&m2);
    printf("\nRow measure representation of first matrix is:\n");
    displayrm(m1);
    printf("\nColumn measure representation of first matrix is:\n");
    displaycm(m1);
    addition(&sum, &m1, &m2);
    multiply(&mul, &m1, &m2);

    return 0;
}

void create(struct matrix * m)
{
    printf("\nEnter rows and columns of matrix resp.: ");
    scanf("%d %d",&(m->r),&(m->c));
    printf("Enter elements of 3*3 matrix.\n");
    int i,j;
    for(i=0;i<(m->r);i++)
    {
        for(j=0;j<(m->c);j++)
        {
            scanf(" %d",&m->a[i][j]);
        }
    }
}

void display(struct matrix m)
{
    for(int i=0;i<(m.r);i++)
    {
        for(int j=0;j<(m.c);j++)
        {
            printf("%d ",m.a[i][j]);
        }
        printf("\n");
    }
}

void addition(struct matrix *sum, struct matrix *m1, struct matrix *m2)
{
    if((m1->r == m2->r) && (m1->c == m2->c))
    {
        printf("\nSum of given two matrix is:\n");
        for(int i=0;i<(m1->r);i++)
        {
            for(int j=0;j<(m1->c);j++)
            {
                sum->a[i][j] = m1->a[i][j] + m2->a[i][j] ; 
            }
        }
        sum->r = m1->r;
        sum->c = m1->c;
        display(*sum);
    }
    else
    printf("\nAddition is not Possible!\n");
}

void multiply(struct matrix *mul, struct matrix *m1, struct matrix *m2)
{
    if(m1->c == m2->r)
    {
        printf("\nMultiplication of given two matrix is:\n");
        for(int i=0;i<(m1->r);i++)
        {
            for(int j=0;j<(m2->c);j++)
            {
                int ans = 0;
                for(int k=0;k<(m1->c);k++)                  
                {
                    ans = ans + (m1->a[i][k]) * (m2->a[k][j]);
                }
                mul->a[i][j] = ans;
            }
        }
        mul->r = m1->r;
        mul->c = m2->c;
        display(*mul);
    }
    else
    printf("\nMultiplication is not Possible!");
}

void displayrm(struct matrix m)
{
    for(int i=0;i<(m.r);i++)
    {
        for(int j=0;j<(m.c);j++)
        {
            printf("%d ",m.a[i][j]);
        }
    }
    printf("\n");
}

void displaycm(struct matrix m)
{
    for(int i=0;i<(m.c);i++)
    {
        for(int j=0;j<(m.r);j++)
        {
            printf("%d ",m.a[j][i]);
        }
    }
    printf("\n");
}
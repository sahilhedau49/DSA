#include<stdio.h>

int n = 7;
int a[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,0,1,0,0,0},
    {1,0,0,1,1,0,0},
    {1,1,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void BFS(int src, int visited[]);
void DFS(int src, int visited[]);

int main()
{
    int visited[]={0,0,0,0,0,0,0};
    BFS(0,visited);
    printf("\n");
    int visited1[]={0,0,0,0,0,0,0};
    DFS(0,visited1);

    return 0;
}

void BFS(int src, int visited[])
{
    int queue[7];
    int front = 0, rear = 0;
    visited[src]=1;
    queue[rear] = src;
    rear++;
    while(front!=rear){
        src = queue[front];
        front++;
        printf("%d  ",src);
        for(int j=0;j<7;j++){
            if(a[src][j]==1 && visited[j]==0){
                visited[j] = 1;
                queue[rear] = j;
                rear++;
            }
        }
    }
}

void DFS(int src, int visited1[])
{
    visited1[src] = 1;
    printf("%d  ",src);
    for(int i=0;i<7;i++)
    {
        if(a[src][i]==1 && (!visited1[i]))
            DFS(i,visited1);
    }
}
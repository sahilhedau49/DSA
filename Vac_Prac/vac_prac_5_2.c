#include <stdio.h>

void quick(int a[], int l, int h);
int partition(int a[], int l, int h);

int main()
{
	int a[5]={5,2,4,1,3};
	int i,n = 5;

	printf("\nArray before sorting:  ");
	for(i=0;i<n;i++)
	printf("%d  ",a[i]);

	quick(a,0,n-1);
	
	printf("\nArray after sorting:  ");
	for(i=0;i<n;i++)
	printf("%d  ",a[i]);
	return 0;
}

void quick(int a[], int l, int h){
	if(l<h){
		int q = partition(a,l,h);
		quick(a,l,q-1);
		quick(a,q+1,h);
	}
}

int partition(int a[], int l, int h){
	int p = h;
	int pivot = a[h];
	int i=l-1;
	int j=l;
	
	while(j<h)
	{
        if (a[j] <= pivot)
        {
            i++;
            int temp = a[j];
            a[j]=a[i];
            a[i]=temp;
        }
		j++;
	}

	int temp = a[h];
	a[h]=a[i+1];
	a[i+1]=temp;
	return i+1;
}
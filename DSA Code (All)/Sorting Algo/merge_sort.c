#include<stdio.h>
#define MAXSIZE 20

void mergeSort(int a[], int l, int h);
void mergeArray(int a[], int l, int m, int h);

int main()
{
    int n;
	printf("Enter length of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter array elements --> ");
	for(int i=0;i<n;i++)
		scanf(" %d",&a[i]);

    mergeSort(a,0,n-1);

	printf("Sorted array elements --> ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
        
    return 0;
}

void mergeSort(int a[], int l, int h)
{
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        mergeArray(a,l,mid,h);
    }
}

void mergeArray(int a[], int l, int m, int h)
{
    int b[20];
    int i=l;
    int j=m+1;
    int k=l;

    while(i<=m && j<=h){
        if(a[i]>a[j]){
            b[k] = a[j];
            k++;
            j++;
        }
        else{
            b[k] = a[i];
            k++;
            i++;
        }
    }

    if(i<=m){
        while(i<=m){
            b[k] = a[i];
            i++;
            k++;
        }
    }
    else{
        while(j<=h){
            b[k] = a[j];
            j++;
            k++;
        }
    }

    for(int i=l;i<=h;i++){
        a[i] = b[i];
    }
}
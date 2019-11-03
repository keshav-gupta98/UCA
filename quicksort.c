#include<stdio.h>
void swap(int arr[],int a,int b)
{
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}
void quickSort(int arr[],int l,int r)
{
	if(l>=r)
		return;
	int last = l;
	for(int i=l+1;i<=r;i++)
	{
		if(arr[i] < arr[l])
		{
			swap(arr,i,++last);
		}
	}
	swap(arr,last,l);
	quickSort(arr,l,last-1);
	quickSort(arr,last+1,r);
}
int main()
{
	int arr[5] = {5,1,1,6,7};
	
	quickSort(arr,0,4);
	for(int i=0;i<5;i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}

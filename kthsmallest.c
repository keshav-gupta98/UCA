#include<stdio.h>
void swap(int arr[],int a,int b)
{
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}
int quickSort(int arr[],int l,int r,int k)
{
	int last = l;
	for(int i=l+1;i<=r;i++)
	{
		if(arr[i] < arr[l])
		{
			swap(arr,i,++last);
		}
	}
	swap(arr,last,l);
	if( last == k )
		return arr[last];
	if( last > k)
		return quickSort(arr,l,last-1,k);
	if(k > last)
		return quickSort(arr,last+1,r,k);
}
int main()
{
	int arr[7] = {3,7,8,3,2,9,10};
	
	int a = quickSort(arr,0,6,2);
	printf("%d\n",a);
}

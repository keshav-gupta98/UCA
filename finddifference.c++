//we are given a sorted array arr and a integer diff,we have to find a[j],a[i] such that a[j]-a[i]=diff and j>i

//e.g. arr={1 4 5 8 9 11} diff=8 output should be 1,9

//we will apply 2 pointer technique in this



#include<iostream>
using namespace std;

void find_diff(int *arr, int size, int diff)
{
	int i = 0;
	int j = i + 1;
	int count = 0;
	while( i < size && j < size)
	{
		if(i!=j && arr[j]-arr[i]==diff)
		{
			cout << arr[i] << ", " << arr[j] << "\n";
			count ++;						//to count number of pairs found
			i++;
			j++;
		}
		else
			if( arr[j] - arr[i] > diff )
			{
				i++;
			}
		else
			{
				j++;
			}
	}

	if( count == 0)								//if no such pairs present
	cout << "Not found\n";
}



int main()
{
	int size;
	cout << "Enter the size of array \n";
	cin >> size;								//size of array
	int *arr=new int[ size ];
	cout << "Enter the elements of array(sorted) \n";
	for( int i = 0; i < size; i++ )
	{
		cin >> arr[i];					//scanning the elements
	}
	cout << "Enter the desired difference \n";
	int diff;
	cin >> diff;						//scanning the desired function							
	find_diff(arr, size, diff);	
}


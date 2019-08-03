//we are given a sorted  array, we have to print the maximum sum of an subarray

//e.g. -2,1,-3,4,-1,3      output should be=6 which is for 4,-1,3      

#include<iostream>
using namespace std;


int main()
{
	cout << "enter the size of array\n";
	int size;
	cin >> size;						//scanning size of array
	int *arr = new int[ size ];				//6
        cout << "enter the elements of array(sorted)\n";



	for( int i = 0; i < size; i++ )
	{
		cin >> arr[i];					//scanning elements of array
	}							//-2,1,-3,4,-1 



	int sum = arr[ 0 ];
	int max = arr[ 0 ];
	for( int i = 0; i < size; i++ )
	{							//sum=-2
		if( sum + arr[ i ] > arr[ i ] )
		{
			sum = sum + arr[ i ];
		}
		else
		{
			sum = arr[ i ];
		}
		if( sum > max )
		{
			max = sum;				//max=
		}
	}


cout << "The maximum sum of subarray is " << max << "\n";
}

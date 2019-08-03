//we have a square matrix

//we have to print matrix in spiral order


#include<iostream>
using namespace std;
int main()
{
	cout << "Enter the size of square matrix\n" ;
	int size;
	cin >> size;						//scanning size of matrix
	int** arr = new int*[ size ];
	for( int i=0; i < size; i++)
	arr[i] = new int[ size ];


	cout << "Enter the elements of matrix\n";
	for( int i = 0; i < size; i++ )
	for( int j = 0; j < size; j++ )				//scanning elements of array
	cin>>arr[i][j];

	cout << "The matrix is :\n";
        for( int i = 0; i < size; i++ )
	{								
		for( int j = 0; j < size; j++ )
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}

	
	int a = 0, b = size, c = 0,d = size;
	cout << "spiral oreder\n";
	int i;
	while( a < b && c < d)
	{
		for( i=c; i < d; i++)
		{
			cout << arr[ a ][ i ] << " ";
		}							
		a++;
		for( i = a; i < b; i++ )
		{
			cout << arr[ i ][ d -1 ] << " ";
		}
		d--;
		if( c < d )
		{
			for( i = d - 1; i >= c; i-- )
			{
				cout << arr[ b - 1][ i ] << " ";
			}
			b--;
		}
		if( a < b )
		{
			for( i = b - 1; i >= a; i-- )
			{
				cout << arr[ i ][ c ] << " ";
			}
			c++;
		}
	}
	cout << "\n";

}

#include<stdio.h>
#include<stdlib.h>

void insert_sort( int *arr, int size )					// sorting function 
{
	for( int i = 0; i < size; i++ )
	{
		int temp = arr[ i ];
		int j = i -1; 
		while( j >= 0 &&  arr[ j ] > temp )			//checking for adjacent pairs till j>=0 for all values less than i
		{
			arr[ j + 1 ] = arr[ j ];
			j--;
		}
		arr[ j + 1 ] = temp;
	}
}

int main()
{
	int size;
	printf( "Enter the size of array:\n" );
	scanf( "%d",&size );

	int *arr = ( int * )malloc( sizeof( int ) * size );
	printf( "Enter the elements of array:\n" );
	for( int i = 0; i < size; i++ )
	{
		scanf( "%d",&arr[i] );					//scanning elements of array
	}

	insert_sort( arr, size );					//calling function to sort array

	printf( "The array after sorting is:\n" );
	printf( "{ %d",arr[ 0 ] );
	for( int i = 1; i < size; i++ )
	{
		printf( ", %d",arr[ i ] );				//printing sorted array
	}
	printf( " }\n" );							
	return 0;
}

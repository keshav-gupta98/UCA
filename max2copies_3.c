// we  have an sorted array of integers

// we have to print maximum 2 copies of each unique element

//e.g. we have {1,1,1,2,2,3,4,4,4,5,6} output should be {1,1,2,2,3,4,4,5,6}

//we will copy the first and last copy of each unique element
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int size;

	printf( "Enter the size of array\n" );
	scanf( "%d" , &size );						//scanning the size of array

	int *arr = (int *)malloc( size * sizeof( int ) );
	int j = 0;

	printf( "Enter the elements of array(sorted)\n" );			//scanning the elements of array
	for( int i = 0; i < size; i++ )
	scanf( "%d" , &arr[ i ] );


	for( int i = 1; i < size - 1; i++ )
	{
		if( arr[ i ] == arr[ i - 1 ] && arr[ i ] != arr[ i + 1 ] )	//checking for last copy
		{
			j++;
			arr[ j ] = arr[ i ];
		}
		if( arr[ i ] == arr[ i + 1 ] && arr[ i ] != arr [ i -1 ] )	//checking for first copy
		{
			j++;
			arr[ j ] = arr[ i ];
		}
		if(arr[ i ] != arr[ i-1 ] && arr[ i ] != arr[ i + 1 ] )        //checking for last copy
		{
			j++;
			arr[ j ]=arr[ i ];
		}
	}

	j++;
	arr[ j ] = arr[ size - 1 ];
	

	printf( "The array of unique elements is:\n" );
	printf( "{ " );
	for( int i = 0; i < j; i++ )
	printf( "%d, ", arr[ i ] );						//printing array
	printf( "%d }\n", arr[j]);
}

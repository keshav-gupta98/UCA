#include<stdio.h>
#include<stdlib.h>


void merge( int *arr, int start, int mid, int end )				//function to merge arrays
{
	int *temp = ( int * )malloc( sizeof( int )*( end - start - 1 ) );   //temporary array of same size as of arr to store sorted elements
	int i = start;
	int j = mid + 1;
	int k = 0;


	while( i <= mid && j <= end )						//comparing elements of left and right array
	{					
		if( arr[ i ] <= arr[ j ] )					//adding arr[i] to temp as it is smaller 
		{
			temp[ k ] = arr[ i ];
			i++;
			k++;
		}
		else							////adding arr[ij to temp as it is smaller
		{
			temp[ k ] = arr[ j ];
			k++;
			j++;
		}
	}

	//adding the remaining elements


	while(i <= mid)
	{
		temp[ k ] = arr[ i ];
		i++;
		k++;
	}
	while( j <= end )
	{
		temp[ k ] = arr[ j ];
		k++;
		j++;
	}

       // copying elements of temp to array

	for( i = start; i <= end; i++ )
	{
		arr[ i ] = temp[ i - start ];
	}
}


void merge_sort( int *arr, int i, int j )
{
	if( i < j )
	{
		int mid = ( i + j ) / 2;

		merge_sort( arr, i, mid );					// sending left array in function

		merge_sort( arr, mid + 1, j );				        //sending right array in function

		merge( arr, i, mid, j );					//calling functon to merge left and right arrays
	}
}



int main()
{
	int size;
	printf( "Enter the size of array:\n" );
	scanf( "%d",&size );
	int *arr=( int * )malloc( sizeof( int ) * size );
	printf( "Enter the elements of array:\n" );
	for( int i = 0; i < size; i++ )
	{
		scanf( "%d",&arr[ i ] );							//scanning the elements of array
	}

	merge_sort( arr, 0, size - 1 );						//calling function and sending starting and ending index 
										// of array and array itself as arguments
	printf("The sorted array is:\n{");
	for( int i = 0; i < size-1; i++ )
	{
		printf(" %d,",arr[i]);						//printing sorted array
	}
	printf(" %d }\n",arr[size-1]);
}

// we are given 3 sorted arrays
// a [1,2,4] b[3,4,7] c[6,8,11] output shoulb be 2 we have to minimize max(a[i],b[j],c[k])-min(a[i],b[j],c[k])




#include<stdio.h>
#include<stdlib.h>
int max_no(int a, int b, int c)				//will return maximum number
{
	if( a >= b && a >= c )
	{
		return a;
	}
	else
	if( b > a && b >= c )
	{
		return b;
	}
	else
	{
		return c;
	}
}
int min_no( int a, int b, int c )				//will return minimum value
{
	if( a < b && a < c )
	{
		return a;
	}
	else
	if( b <= a && b < c )
	{
		return b;
	}
	else
	{
		return c;
	}
}
int func( int size_1, int *arr1, int size_2, int *arr2, int size_3, int *arr3)
{
	int min,max;
	int diff = 99999;
	int i = 0,j = 0,k = 0;
	while( i<size_1 && j<size_2 && k<size_3)
	{								
		max = max_no( arr1[i], arr2[j], arr3[k] );			
		min = min_no( arr1[i], arr2[j], arr3[k] );
		if( ( max-min ) < diff )
		{
			diff = max - min;
		}
		
		if( arr1[ i ] == min )
		i++;
		if( arr2[ j ] == min )						//increasing the index of that array which has
		j++;								//smallest element
		if( arr3[ k ] == min )
		k++;

	}
	return diff;	
}	
int main()
{
	int size_1;						//to input data of first array							
	printf( "Enter the size of first array\n" );
	scanf( "%d", &size_1 );
	int arr1[size_1];
	printf( "Enter the elements of array(sorted)\n" );
	for(int i = 0; i < size_1; i++ )
	scanf( "%d", &arr1[ i ] );



	int size_2;
	printf( "Enter the size of second array\n" );
	scanf( "%d", &size_2 );					//to input data of second array
	int arr2[ size_2 ];
	printf( "Enter the elements of array(sorted)\n" );
	for(int i = 0; i < size_2; i++ )
	scanf( "%d", &arr2[ i ] );


	int size_3;
	printf( "Enter the size of third array\n" );
	scanf( "%d", &size_3 );
	int arr3[ size_3 ];					//to input array of third array
	printf( "Enter the elements of array(sorted)\n" );
	for( int i = 0; i < size_3; i++ )
	scanf( "%d", &arr3[ i ] );

	int min_diff = func( size_1, arr1, size_2, arr2, size_3, arr3 );		//call to function

	printf( "The min difference of maximum difference found in among elements in three array is %d\n", min_diff );
}

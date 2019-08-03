//we have an sorted array ,we have to print the indexes of 3 three valus whose sum is closest to a given integer

// array={-8,-2,3,6,7,8}     target is 5 output should be 0 3 4  

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size;
	printf( "Enter the size of array\n" );
	scanf( "%d", &size );				//scanning size of array
	int *a=(int *)malloc( size * sizeof( int ) );
	printf( "Enter the elements of array(sorted)\n" );
	for(int i = 0; i < size; i++ )				//scanning elements of array
	scanf( "%d", &a[ i ] );



	printf( "Enter the target\n" );
	int target;					//scanning the target value
	scanf( "%d", &target );


	int k = size - 1;
	int j;
	int i = 0;
	for( i = 0;i < size - 2; i++)
	{								//searching between j and k initializing  j=i+1
		j = i + 1;						
		k = size - 1;
		while( j <= k )
		{
			if( a[ i ] + a[ j ] + a [ k ] == target )
			{
				break;
			}
			
			else
			if(a[ i ] + a[ j ] + a[ k ] > target )
			{
				k--;
			}
			else
			{
				j++;
			}
		}
		if( a[ i ] + a[ j ] + a[ k ] == target )
		{
			break;
		}
	}
	printf( "The sum of values at indexes : " );
	printf( "%d %d %d ", i, j, k );						//printing 
	printf( "is closest to %d\n",target );
	
}

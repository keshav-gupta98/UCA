//we are given two arrays

//one is an array of lower limits and other is array of upper limits we have to find that element which occurs maximum times between range 

//e.g. arr1={2,1,3} and arr2={5,3,9} output should be 3


#include<stdio.h>
#include<stdlib.h>


int main()
{
	printf( "Enter the size of array\n" );
	int size;							//scanning size of array
	scanf( "%d" , &size);

	int *first_array = ( int * )malloc( size * sizeof( int ) );
	int *second_array = ( int * )malloc( size * sizeof( int ) );

	printf( "Enter the lower and upper limits\n" );			//scanning lower limits and upper limits
	for( int i = 0; i < size; i++ )					// 2 5 1 3 3 9
	scanf( "%d%d", &first_array[ i ], &second_array[ i ] );



	//sorting of both arrays
	for( int i = 0;i < size; i++ )
	{
		for( int j = i + 1; j < size; j++ )				
		{
			if( first_array[ i ] > first_array[ j ] )
				{
					int temp1 = first_array[ i ];			
					first_array[ i ] = first_array[ j ];
					first_array[ j ] = temp1;
				}
			if( second_array[ i ] > second_array[ j ] )
				{
					int temp2 = second_array[ i ];
					second_array[ i ] = second_array[ j ];
					second_array[ j ] = temp2;
				}
		}
	}


		//after sorting {1,2,3} {3,5,9}



	int *arr = ( int * )calloc( second_array[ size - 1 ], sizeof( int ) );    //assigning 0 to all elements of array
										  //{0,0,0,0,0,0,0,0,0}
				
	int previous = 0;
	int max = 0;
	for( int i = 0; i < size; i++ )
	{
		arr[ first_array[ i ] ]++;
		arr[ second_array[ i ] + 1]--;
	}

				// arr={0,1,1,1,-1,0,-1,0,0}

	for( int i = 0; i < second_array[ size - 1 ]; i++ )
	{
		if( previous + arr[ i ] > max)					 //prev=0 1 2 3 2 2 1 1 1
			max = previous + arr[ i ];				  //max=0 1 2 3 3 3 3 3 3
		previous = previous + arr[ i ];
	}
   			//final value of previous and max are 1 and 3 respectively.


	printf( "maximum element that occured between range is %d\n" , max );			//3
	
}

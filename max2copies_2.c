// in this question we have an array of sorted integers

// we have to print maximum 2 copies of each unique elemenet of this array

// e.g. {1,1,2,3,4,4,4,4,4,5,5,6}  output should be  {1,1,2,3,4,4,5,5,6}

// in this question we will copy the last two copies of each unique element



#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size;

	printf( "Enter the size of array\n" );

	scanf( "%d", &size );                                            //scanning the size of array

	int *arr=( int * )malloc( size*sizeof( int ) );

	printf( "Enter the elements of array(sorted)\n" );                       //scanning the element of  array

	for( int i = 0; i < size; i++ )
	{
		scanf( "%d" , &arr[ i ] );
	}

	int j = 0;

	for( int i = 1;i < size; i++ )

	{

		if( arr[ i ] == arr[ i+1 ] && arr[ i ] == arr[ i+2 ] )          // checking whether next element and next
                {                                                               // next to next element are same or not
			continue;
		}

		else							    //adding elements from back
		{
			arr[ j ] = arr[ i ];
			j++;
		}

	}


	printf( "The array of unique elements is:\n" );
	printf("{ %d",arr[0]); 					//printing the array
	for( int i = 1 ;i < j; i++ )
	printf( ", %d",arr[ i ] );

	printf(" }\n");
}


// We have an array of integers which is sorted,we have to print  maximum 2 copies of an element 

//e.g.  we have array {1,1,1,2,2,3,4,4,4,4,6,7} output should be {1,1,2,2,3,4,6,7}

//in this we declare a variable flag which will tell us previous value entered is equal to current element or not.




#include<stdio.h>
#include<stdlib.h>


int main()
{
	int size;
	printf( "Enter the size of array\n" );
	scanf( "%d" , &size);                                                            //scanning size of array
	int *a = (int *)malloc( size*sizeof( int ) );                       
	printf( "Enter the elements of array(sorted)\n" );                                      //scanning elements of array
	for(int i = 0; i < size; i++)
	scanf( "%d", &a[ i ] );



	int j = 0;
	int flag = 1;
	for( int i = 1; i < size; i++ )
	{
		if( a[i] == a[j] && flag == 1)			
		{
			j++;
			a[ j ] = a[ i ];
			flag = 0;
		}
				
		else if( a[ i ] != a[ j ] )			 
		{
			j++;
			a[ j ] =a[ i ];
			flag = 1;
		}
	}

	printf( "The array of unique elements is:\n" );
        printf( "{ " );
	for( int i = 0; i < j; i++)                                   //printing the elements
	printf( "%d, ", a[ i ] );
	printf("%d }\n", a[ j ]);

}

// we are given a square matrix

// we have to rotate it by 90 degree;


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int size;
	printf( "Enter the size of square matrix\n" );					//scanning size of matrix
	scanf( "%d" , &size );

	int **arr = (int **)malloc( sizeof( int ) * size );

	for( int i= 0 ;i < size; i++ )
	{
		arr[ i ]=(int *)malloc( sizeof( int ) * size );
	}

	printf( "Enter the elements of matrix\n" );					//scanning elemnts of matrix
	for(int i = 0; i < size; i++)
		for(int j = 0;j < size; j++)
			scanf( "%d",&arr[ i ][ j ] );

	printf( "orignal matrix:\n" );
	for(int i = 0; i < size; i++ )
	{	
		for( int j = 0; j < size; j++ )					       //printing orignal matrix
		{
			printf( "%d ",arr[ i ][ j ] );
		}
		printf( "\n" );
	}




	for( int i = 0; i < size / 2; i++ )
	{
		for( int j = i; j < size - 1 - i; j++ )
		{
			int temp = arr[ i ][ j ];
			arr[ i ][ j ] = arr[ size - 1 -j ][ i ];
			arr[ size - 1 - j ][ i ]=arr[ size - 1 - i ][ size - 1 - j ];
			arr[ size - 1 - i ][ size - 1 - j ]=arr[ j ][ size - 1 - i ];
			arr[ j ][ size- 1 - i ] = temp;
		}
	}




	printf( "new matrix:\n" );
	for( int i = 0; i < size; i++ )
	{	
		for( int j = 0; j < size; j++ )							//printing matrix after rotation
		{
			printf( "%d ", arr[ i ][ j ]);
		}
		printf("\n");
	}	
}

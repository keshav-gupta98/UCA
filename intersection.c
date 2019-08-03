//we have given two sorteb arrays and we have find their intersection

//e.g. arr1={1 1 2 2 3 3 3 4 4 5 6} arr2={3 3 5 6 7} output should be  3 3 5 6

//we will apply two pointer technique

#include<stdio.h>
#include<stdlib.h>


void find_inter( int size_1, int *arr1, int size_2, int *arr2)
{	
	int flag=0;
	int i = 0, j = 0;							//i is index for arr1 and j is index for arr2


	while( i < size_1 && j < size_2 )
	{
		if( arr1[ i ] < arr2[ j ] )					//incrementing i because as array is sorted
		i++;								//so common element must be at higher index

		else
		{
			if( arr1[ i ] > arr2[ j ])				//incrementing j because as array is sorted
			j++;							//so common element must be at higher index

			else
			{
				printf( "%d ", arr1[ i ] );
				i++;
				j++;						//printing arr[i] and arr[j] if they are equal
				flag=1;
			}

		}

	}

	if( flag == 1)
	{
		printf( "are the common elements\n" );
	}
	if( flag == 0 )
	printf( "No common elements found\n");					//in case there are no common elements
}



int main()
{
	int size_1;
	printf( "Enter the size of array\n" );
	scanf( "%d", &size_1 );							//scanning size of first array


	int *arr1=( int *)malloc( size_1 * sizeof( int ) );
	printf("Enter the elements of array(sorted)\n");
	for(int i=0;i<size_1;i++)
	scanf("%d",&arr1[i]);							//scanning elements of first array


	int size_2;
	printf("Enter the size of array\n");
	scanf("%d",&size_2);                                                    //scanning size of second array


	int *arr2=(int *)malloc(size_2*sizeof(int));
	printf("Enter the elements of arrayI(sorted)\n");
	for(int i=0;i<size_2;i++)
	scanf("%d",&arr2[i]);							//scannimg elements of second array


	find_inter(size_1,arr1,size_2,arr2);					//calling function
}


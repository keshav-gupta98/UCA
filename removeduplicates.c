//we have an sorted array

//we have to remove duplicate arrays without storing in another array

// e.g. array={1,1,2,4,4,4,4,5,8,8,9}   output -> {1,2,4,5,8}


#include<stdio.h>
#include<stdlib.h>


int func(int *arr,int size)
{							
	int j=0;
	for(int i=1;i<size;i++)
	{
		if(arr[i]!=arr[j])					//adding elements from behind
		{
			j++;
			arr[j]=arr[i];		
		}
	}						// arr={1,2,4,5,8,9,4,5,8,8,9} 
	return j+1;					//  j=6
							//returning the index of last unique element
}



int main()
{
	printf( "Enter the number of elements\n" );
	int size;							//scanning size of array
	scanf( "%d", &size );
	int *arr=(int *)malloc( sizeof(int) * size );
	printf( "Enter the elements(sorted)\n" );
	for(int i = 0; i < size; i++)
	{
		scanf( "%d", &arr[ i ] );				//{1,1,2,4,4,4,5,8,8,9}
	}


	int n_size = func( arr, size );



	printf( "After removal of duplicates from array" );
	printf( "{ %d", arr[0] );					//{1,2,4,5,8,9}
	for( int i = 1; i < n_size; i++ )
		printf( ", %d", arr[i] );
	printf( " }\n" );
	return 0;
}

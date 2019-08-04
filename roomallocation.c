


#include<stdio.h>
#include<stdlib.h>


struct dates										//structure which will store arrival and departure dates
{											//of people
	int arrival;
	int departure;
};



int comparator(const void *p, const void *q)  						//function to compare arrival dates
{ 
    int a = ( ( struct dates * )p ) -> arrival; 
    int b = ( ( struct dates * )q ) -> arrival;  
    return ( a - b ); 
}

 
int check_possibility( int rooms, int peeps, struct dates *arr )						//function to check posdibility
{
	rooms--;										//bcoz room will be always available for ist 
												//customer
	int flag = 0;
    	for( int i = 0; i < peeps - 1; i++ )
    	{
        	if( ( arr[ i ].departure >= arr[ i + 1 ].arrival ) && ( rooms <= 0 ) )
        	{
            		flag = 1;
            		break;
        	}
        	if( ( arr[ i ].departure >= arr[ i + 1 ].arrival ) && ( rooms != 0 ) )
        	{
            		rooms--;								//bcoz room will not be available
												//till i leaves the room
            		if( arr[ i ].departure > arr[ i + 1 ].departure )
            			rooms++;							//bcoz rooms 1 more room will be available
        	}										// after i+1 leaves room	
    	}


    	if( flag == 1 )										//if flag=1 alllocation is possible
    	{
        	return 0;
    	}
    	else
    	{
        	return 1;
    	}
}


int main()
{
	int rooms;
	int peeps;

	printf( "Enter the number of rooms available\n" );
	scanf( "%d",&rooms );


	printf( "Enter the number of people\n" );
	scanf( "%d",&peeps );
	struct dates *arr = ( struct dates * )malloc( sizeof( struct dates ) * peeps );


	printf( "Enter the arrival and departure dates\n" );
	for( int i = 0; i < peeps; i++ )
	{
	    scanf( "%d%d", &arr[ i ].arrival, &arr[ i ].departure );			//scanning the arrival and departure dtes of peeps
	}


	qsort( arr, peeps, sizeof( arr[ 0 ] ), comparator );				//sorting according to arrival dates
	
	int result = check_possibility( rooms, peeps, arr );				//calling function to check possibility
	if( result == 1 )
	{
		printf( "POSSIBLE\n" );
	}
	else
	{
		printf( "NOT POSSIBLE\n" );
	}
	return 0;
}
	

// we have a list of size n
// we have to remove element at n/2+1 index if elements are present else at (n+1)/2
 
#include<stdio.h>
#include<stdlib.h>


struct node										// definition of linkedliist
{
    int value;
    struct node *next;
};

void print( struct node * head )   							// print linkedlist 
{					
    struct node * current = head;

    while ( current != NULL ) 
    {
        printf( "%d ", current -> value );
        current = current -> next;
    }
    printf( "\n" );
}


void add( struct node **h, int a )                					//insert at last 
{
     struct node *new = ( struct node * )malloc( sizeof( struct node ) );
        new -> value = a;
        new -> next = NULL;
    if( *h == NULL )
    {
        *h = new;
    }
    else
    {
        struct node *curr = ( struct node * )malloc( sizeof( struct node ) );
        curr = *h;
        while( curr -> next != NULL )
        {
            curr = curr -> next;
        }
        curr -> next = new;
    }
}


void remove_middle( struct node **head )						// function to remove middle element
{
	struct node *first = *head;
	struct node *second = *head;
	
	// if elements are even list will traverse till second last else till third last
	while( ( second -> next -> next != NULL ) && ( second -> next -> next -> next != NULL ) )	
	{
		second =second -> next -> next;
		first = first -> next;
	}	
			
	// we have to delete the next element of first 
	struct node *temp = first -> next;			
	first -> next = temp -> next;
	free( temp );
}


int main()
{
 struct node *head = NULL;
 printf( "Enter the number of elements\n" );
 int n;
 scanf( "%d",&n );
 printf( "Enter the elements\n" );						// enter the elements
 for( int i = 0; i < n; i++ )
 {
 	int a;
 	scanf( "%d" ,&a );
 	add( &head, a );
 }
 
 remove_middle( &head );							// calling function to remove middle element
 printf ("Linked list after removal of middle element is\n" );
 print( head );									// printing list
}

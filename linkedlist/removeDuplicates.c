// construct a linked list
// remove duplicates if elements are sorted

#include<stdio.h>
#include<stdlib.h>


struct node											//definition of linked list
{
    int value;
    struct node *next;
};


void push_front( struct node **h, int a )							// add at first
{
    struct node *new = ( struct node * )malloc( sizeof( struct node ) );		
    new -> value = a;									
    new -> next = *h;
    *h = new;
}

void push_back( struct node **h, int a )                					//insert at last 
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


void print( struct node * head )   									// print linkedlist 
{					
    struct node * current = head;

    while ( current != NULL ) 
    {
        printf( "%d ", current -> value );
        current = current -> next;
    }
    printf( "\n" );
}


void remove_duplicates( struct node **head )					// function to remove duplicates
{
    struct node *first = *head;							// constructing new node pointing to first node
    struct node *second = first -> next;					// constructing new node pointing to second node
    struct node *temp;
    while( second )
    {
        if( first -> value == second -> value )					// if values are same then first will point to second-> next
        {									// second is deleted
            first -> next = second -> next;					// new second will start pointing to second -> next
            temp = second;
            free( second );
            second = temp -> next;
        }
        else									// if values are different then increment first and second
        {
            first = first -> next;
            second = second -> next;
        }
    }
}

int main()
{
	struct node *head = NULL;
	int n;
	printf( "Enter the number of elements\n" );
	scanf("%d",&n);
	printf( "Enter the elements(sorted)\n" );
	for( int i = 0; i < n; i++ )
	{
		int a;
		scanf( "%d",&a );
		push_back( &head, a );
	}
	
	
	remove_duplicates( &head );								//calling function to remove duplicates
	
	printf( "The list after removal of dupplicates is\n" );
	print(head);										// printing the list
}

#include<stdio.h>
#include<stdlib.h>

struct node										// definition of linked list
{
    int value;
    struct node *next;									// pointer pointing to next node
};


void push_front( struct node **h, int a )							// add at first
{
    struct node *new = ( struct node * )malloc( sizeof( struct node ) );		//constructing new node
    new -> value = a;									// assigning value to new node
    new -> next = *h;									// new node will point first node
    *h = new;										// head will point to new node
}
void print( struct node * head )   						// print linkedlist 
{					
    struct node * current = head;

    while ( current != NULL ) 							// traversing till end of list
    {
        printf( "%d ", current -> value );
        current = current -> next;
    }
    printf( "\n" );
}

void push_back( struct node **h, int a )                					//insert at last 
{
     struct node *new = ( struct node * )malloc( sizeof( struct node ) );
        new -> value = a;
        new -> next = NULL;
    if( *h == NULL )										// if list is empty 
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

void pop_back( struct node **h )				                 	//remove from last
{
    if( *h == NULL )
    {
        printf( "No element to delete" );
    }
    else
    {
        struct node *curr = ( struct node * )malloc( sizeof( struct node ) );
        curr = *h;
        while( curr -> next -> next != NULL )
        {
            curr = curr -> next;
        }
        struct node *curr1 = ( struct node * )malloc( sizeof( struct node ) );
        curr1 = curr -> next;
        free( curr1 );
        curr -> next = NULL;
    }
}
void swapnodes( struct node **head,int a, int b)
{
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	struct node *x = (struct node *)malloc(sizeof(struct node));
	struct node *y = (struct node *)malloc(sizeof(struct node));
	struct node *prevX = (struct node *)malloc(sizeof(struct node));
	struct node *prevY = (struct node *)malloc(sizeof(struct node));
	curr = *head;
	prevX= NULL;
	x = *head;
	prevY = NULL;
	y = *head;
	while(x!=NULL && x-> value !=a)
	{
		prevX = x;
		x = x -> next;
	}
	while(y!=NULL && y->value != b)
	{
		prevY = y;
		y = y -> next;
	}
	//printf("%d %d %d %d\n",x -> value,y -> value,prevX -> value,prevY -> value);
	if(prevX==NULL)
	{
		struct node *a1= y ->next;
		y ->next = x->next;
		x -> next = a1;
		*head = y;
		prevY -> next = x;
	}
	else if(prevY==NULL)
	{
		struct node *a1 = x ->next;
		x -> next = y -> next;
		y -> next = a1;
		*head = x;
		prevX -> next = y;
	}
	else if( prevX!=NULL && prevY!=NULL )
	{
		struct node *a1 = x -> next;
		x -> next = y -> next;
		y -> next = a1;
		prevX -> next = y;
		prevY -> next = x;
	}
}
int main()
{
	struct node *head = NULL;
	printf("Enter the number of initial elements\n");
	int n;
	scanf("%d",&n);
	printf("Enter the elements\n");
	int i = 0;
	for( i = 0; i < n; i++ )
	{
		int c;
		scanf("%d",&c);
		push_back(&head,c);
	}
	print(head);
	int a;
	int b;
	printf("Enter the values to be swapped\n");
	scanf("%d",&a);
	scanf("%d",&b);
	swapnodes(&head,a,b);
	print(head);
}

struct node *swapadjacent( struct node *head ) 							// function to swap adjacent pairs
{ 
    // If linked list is empty or there is only 
    // one node in list 
    if ( head == NULL || head -> next == NULL ) 
        return head; 
  
    // Fix the head and its next explicitly to 
    // avoid many if else in while loop 
    struct node *curr = head -> next -> next; 
    struct node *prev = head; 
    head = head -> next; 
    head -> next = prev; 
  
    // Fix remaining nodes 
    while ( curr != NULL && curr->next != NULL ) 
    { 
        prev -> next = curr -> next; 
        prev = curr; 
        struct node *next = curr -> next -> next; 
        curr -> next -> next = curr; 
        curr = next; 
    } 
      
    prev -> next = curr; 
    return head;
} 
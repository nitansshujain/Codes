Code: Midpoint of LL
Given a linked list, find and return the midpoint.
If the length of linked list is even, return the first mid point.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 2 3 4 5 -1
Sample Output 1 :
3
Sample Input 2 :
1 2 3 4 -1
Sample Output 2 :
2
	
	
/***************************************************** SOLUTION **********************************************************************/
	
	
// for odd and even length
node* midpoint_linkedlist(node *head)
{
    node *slow = head;
    node *fast = head -> next;
    
    if(head != NULL){
        while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
    }
}

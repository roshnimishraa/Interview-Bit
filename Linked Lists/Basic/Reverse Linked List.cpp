Iterative method 
TC : O(N) 
SC : O(1) In-place
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
ListNode* temp = A;
ListNode* prev = NULL;
while(temp != NULL)
{
    ListNode* front = temp->next;
    temp->next = prev;
    prev = temp;
  temp = front;
}    
return prev;
}


Recursive method
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if(A==NULL || A->next == NULL){
        return A;
    }
    ListNode* newHead = reverseList(A->next);
    ListNode* front = A->next;
    front->next = A;
  A->next = NULL;
  return newHead;
}

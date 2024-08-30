Brute Force 
TC : O(L) + O(L-N)
SC : O(1) 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A == NULL){
        return NULL;
    }
    ListNode* temp = A;
 int count=0;
 while(temp != NULL){
     count++;
     temp = temp->next;
 }
 if(B>=count)
 {
     ListNode* newHead = A->next;
     delete(A);
     return newHead;
 }
 int res = count-B;
 temp = A;
 while(temp != NULL){
     res--;
     if(res == 0){
         break;
     }
     temp = temp->next;
 }
 ListNode* deleteNode =temp->next;
 temp->next = temp->next->next;
 delete(deleteNode);
 return A;
 
}

Optimized Approach 
TC : O(N)
SC : O(1)
  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // optimized approach 
    // initially move fast pointer by B steps 
    // then move slow and fast pointer by 1 step simulataneously
    ListNode* fast = A;
    for(int i=0; i<B; i++)
    {
       if (fast->next != NULL) {
            fast = fast->next;
        } else {
            // If B is greater than or equal to the length of the list,
            // remove the first node (i.e., return A->next)
            return A->next;
        }
    }

    ListNode* slow = A;
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // now slow pointer points to NodeToBeDeleted prev
    ListNode* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete(deleteNode);
    return A;
}

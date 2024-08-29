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
 ListNode* findMiddle(ListNode* A)
 {
    //  modified Tortoise and Hare Algorithm to get 1st middle 
    ListNode* slow = A;
    ListNode* fast = A->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    } 
    return slow;
 }
 
 ListNode* reverseLL(ListNode* A)
 {
 
     ListNode* curr = A;
     ListNode* prev = NULL;
     while(curr != NULL){
         ListNode* next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
     }
     return prev;
 }
int Solution::lPalin(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return true;
    }
    ListNode* middle = findMiddle(A);
    // Recursive step: Reverse the remaining 
    // part of the list and get the new head
    ListNode* newHead = reverseLL(middle->next);
    ListNode* first = A;
    ListNode* second = newHead;
    // compare 
    while(second != NULL)
    {
        if(first->val != second->val)
        {
            // reverse second half to get the original position 
            reverseLL(newHead);
            return false;
        }
      first = first->next;
      second = second->next;
    }
    // reverse second half back to original state
    reverseLL(newHead);
    return true;
}

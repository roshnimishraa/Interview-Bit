TC : O(N)
SC : Recursion stack space O(N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if(A == NULL || A->next == NULL){
        return A;
    }
    ListNode* newHead = reverseList(A->next);
    ListNode* front = A->next;
    
    front->next = A;
    A->next = NULL;
    return newHead ;
}

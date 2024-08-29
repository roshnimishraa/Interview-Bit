Time Complexity: O(N1+N2)
Space Complexity : O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while(A != NULL && B != NULL)
    {
        if(A->val <= B->val)
        {
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }
    return dummy->next;
}

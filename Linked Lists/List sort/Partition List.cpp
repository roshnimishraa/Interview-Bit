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
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* smallH = new ListNode(0);
    ListNode* largeH = new ListNode(0);
    ListNode* t1 = smallH;
    ListNode* t2 = largeH;
    while(A != NULL)
    {
        if(A->val < B)
        {
            t1->next = A;
            t1 = t1->next;
        }
        else{
            t2->next = A;
            t2= t2->next;
        }
        A = A->next;
    }
    t1->next = largeH->next;
    t2->next = NULL;
    return smallH->next;
}

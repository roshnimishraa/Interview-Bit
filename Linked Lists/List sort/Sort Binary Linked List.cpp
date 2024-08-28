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
ListNode* Solution::solve(ListNode* A) {
    ListNode* t1 = A;
    ListNode* t2 = A;
    while(t1 != NULL)
    {
        if(t1->val == 0)
        {
            swap(t1->val, t2->val);
            t2 =t2->next;
        }
        t1 = t1->next;
    }
    return A;
}

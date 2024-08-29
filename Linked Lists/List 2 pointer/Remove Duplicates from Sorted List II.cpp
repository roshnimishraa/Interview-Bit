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
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL){
        return A;
    }
    // if we have to delete 1st node then we don't access of head for that declare dummy node
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* temp = dummy;
   while(temp->next != NULL && temp->next->next != NULL)
   {
    //    check two adjacent values are same or not
    if(temp->next->val == temp->next->next->val)
    {
        int variable = temp->next->val; //nodetobedeleted val
        // delete them until nodes are equal
        while(temp->next != NULL && temp->next->val == variable)
        {
            temp->next = temp->next->next;
        }
    }
    else{
        temp = temp->next;
    } 
   }
   return dummy->next;
}

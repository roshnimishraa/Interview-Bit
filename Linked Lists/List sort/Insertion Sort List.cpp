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
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    ListNode* sortedList = new ListNode(A->val);
    ListNode* curr = A->next;
    while(curr != NULL)
    {
        // case 1 : prepend
        if(curr->val < sortedList->val)
        {
            ListNode* newFirst = new ListNode(curr->val);
            newFirst->next = sortedList;
            sortedList = newFirst;
        }
        else{
            // case 2 : append
            ListNode* prev = sortedList;
            ListNode* pointer = sortedList->next;
            while(1){
                if(pointer == NULL || curr->val < pointer->val)
                {
                    ListNode* temp = new ListNode(curr->val);
                    temp->next = prev->next;
                    prev->next = temp;
                    break;
                }
                else{
                // if curr->val > pointer iterate over the sortedlist and update the prev pointer
                prev = prev->next;
                pointer = pointer->next;
                }
            }
        }
        curr = curr->next;
    }
    return sortedList;
}

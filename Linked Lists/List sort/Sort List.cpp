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
     ListNode* slow = A;
     ListNode* fast = A->next; //to get first middle 
     while(fast != NULL && fast->next != NULL)
     {
         slow = slow->next;
         fast = fast->next->next;
     }
     return slow;
 }
 
 ListNode* mergeTwoList(ListNode* list1, ListNode* list2)
 {
   ListNode* dummyNode = new ListNode(-1);
   ListNode* temp = dummyNode;
   while(list1 != NULL && list2 != NULL)
   {
     if(list1->val < list2->val)
     {
         temp->next = list1;
         temp = list1;
         list1 = list1->next;
     }    
     else{
         temp->next = list2;
         temp = list2;
         list2 = list2->next;
     }
   }
   if(list1 != NULL) {
       temp ->next = list1;
   }
   else{
       temp->next = list2;
   }
   return dummyNode->next;
 }
 
ListNode* Solution::sortList(ListNode* A) {
    if(A == NULL || A->next == NULL)
    {
        return A;
    }
    ListNode* middle = findMiddle(A);
    ListNode* right = middle->next;
    middle->next = NULL; //list2
    ListNode* left = A; //list1
      // Recursively sort the left and right halves
    left = sortList(left); 
    right = sortList(right);
    return mergeTwoList(left, right);
}

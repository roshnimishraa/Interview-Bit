Method 1 - By Hashing 
TC : O(n + m)
SC : O(n)
  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    unordered_map<ListNode*,int> mp;
    ListNode* temp1 = A;
    while(temp1 != NULL)
    {
        mp[temp1] = 1;
        temp1 = temp1->next;
    }
    temp1 = B;
    while(temp1!= NULL)
    {
        if(mp.find(temp1) != mp.end())
        return temp1;
        temp1 = temp1->next;
    }
    return NULL;
}

Method 2 - By  Difference in length

TC : O(N1) + O(N2) + O(N2-N1) + O(N1) ~ O(N1+ 2N2) ~ O(N1 + N2) 
SC : O(1) 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* collisionPoint(ListNode* t1, ListNode* t2, int d) {
  
    while (d--) {
        t2 = t2->next;
    }
  
    while (t1 != NULL && t2 != NULL) {
        if (t1 == t2) return t1;
        t1 = t1->next;
        t2 = t2->next;
    }
 
    return NULL;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    if (A == NULL || B == NULL) return NULL;

    int n1 = 0, n2 = 0;
    ListNode* t1 = A;
    ListNode* t2 = B;

  
    while (t1 != NULL) {
        n1++;
        t1 = t1->next;
    }
    
    while (t2 != NULL) {
        n2++;
        t2 = t2->next;
    }


    if (n1 < n2) {
        int d = n2 - n1;
        return collisionPoint(A, B, d);
    } else {
        int d = n1 - n2;
        return collisionPoint(B, A, d);
    }
}

Method 3 : Optimised Approach 
Time Complexity: O(2*max(length of list1,length of list2))

Space Complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
 if(A == NULL || B == NULL) return NULL;
 ListNode* t1 = A;
 ListNode* t2 = B;
 while(t1 != t2 )
 {
     t1 = t1->next;
     t2 = t2->next;
    //  collision point
    if(t1 == t2) {
        return t1;
    }
    //  opposite head
    if(t1 == NULL) t1 = B;
    if(t2 == NULL) t2 = A;
    
 }
 return t1;
}

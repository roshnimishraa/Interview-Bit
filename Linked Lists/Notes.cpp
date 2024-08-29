Why we do modification in Tortoise-Hare (slow-fast) Algorithm

Standard Algorithm 
slow = head;
fast = head;
while(fast != NULL || fast->next != NULL) 
{
slow = slow->next;
fast = fast->next->next;
}
return slow; //middle


So, in the case of standard Algorithm for EVEN LENGTH LIST this algorithm return 2nd middle of the Linked List. 

Therefore, when we need to Find 1st middle of the Linked List we do modification in Tortoise-Hare Algorithm
slow = head;
fast = head;
while(fast != NULL || fast->next != NULL) 
{
slow = slow->next;
fast = fast->next->next;
}
return slow; //middle

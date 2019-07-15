/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head,*q = head;
    if(p == NULL)
        return false;
    else
    {
        while(1)
        {
            if(p->next == NULL||p->next->next == NULL)
                return false;
            q = q->next;
            p = p->next->next;
            if(p == q)
                return true;
        }
    }
}
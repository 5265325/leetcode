/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* new = NULL;
    struct ListNode** p = &new;
    
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL || l2 != NULL && l1->val > l2->val) {
            *p = l2;
            l2 = l2->next;
            p = &((*p)->next);
        }
        else {
            *p = l1;
            l1 = l1->next;;
            p = &((*p)->next);
        }
    }
    return new;
}
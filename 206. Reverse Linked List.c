/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *left = head, *middle = head->next, *right = middle->next;
    left->next = NULL;
    
    while(right != NULL) {
        middle->next = left;
        left = middle;
        middle = right;
        right = right->next;
    }
    middle->next = left;
    
    return middle;
}
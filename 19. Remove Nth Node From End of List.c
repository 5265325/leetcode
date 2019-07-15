/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* front = head;
    struct ListNode* behind = head;
    
    while(n-- != 0) {
        front = front->next;
    }
    
    if (front == NULL) {
        return head->next;
    }
    
    while (front->next != NULL) {
        front = front->next;
        behind = behind->next;
    }
    
    behind->next=behind->next->next;
    return head;
}
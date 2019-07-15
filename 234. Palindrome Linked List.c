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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// bool isPalindrome(struct ListNode* head) {
//     if (head == NULL || head->next == NULL) {
//         return true;
//     }
//     struct ListNode *left = head, *right = head;
//     int len = 0;
    
//     while (right) {
//         right = right->next;
//         len++;
//     }
    
//     struct ListNode *temp = head;
//     for (int i = 0; i < len / 2; i++) {
//         temp = temp->next;
//     }
//     right = reverseList(len % 2 > 0 ? temp->next : temp);
//     temp->next = NULL;
    
//     while (right != NULL) {
//         if (left->val != right->val) {
//             return false;
//         }
//         left = left->next;
//         right = right->next;
//     }
//     return true;
// }

bool isPalindrome(struct ListNode* head) {
    struct ListNode *fast = head, *slow = head, *temp = NULL;
    while (fast) {//快慢指针找到链表中点
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
    while (slow) {
        fast = slow->next;
        slow->next = temp;
        temp = slow;
        slow = fast;
    }
    fast = head;
    slow = temp;
    while (fast && slow) {
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
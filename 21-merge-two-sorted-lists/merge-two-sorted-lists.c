/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* cur = dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            cur->next = list1;
            cur = cur->next;
            list1 = list1->next;
        }
        else {
            cur->next = list2;
            cur = cur->next;
            list2 = list2->next;
        }
    }

    if (!list1 && list2) cur->next = list2;
    if (list1 && !list2) cur->next = list1;
    if (!list1 && !list2) return NULL;
    return dummy->next;
}
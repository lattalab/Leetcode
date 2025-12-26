/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // create dummy head
    struct ListNode *dummy_head = malloc(sizeof(struct ListNode));
    dummy_head->next = head;

    // 2 pointer
    struct ListNode *slow, *fast;
    fast = dummy_head;
    slow = dummy_head;
    for (int i=0; i<n+1; i++) fast = fast->next;

    // move fast pointer to the end
    while (fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    // thus, we can delete the desired node
    struct ListNode *tmp;
    tmp = slow->next;
    slow->next = tmp->next;
    free(tmp);

    // delete the dummy head
    head = dummy_head->next;
    free(dummy_head);
    return head;
}
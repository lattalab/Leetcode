/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    // create dummy head
    struct ListNode *top = malloc(sizeof(struct ListNode));
    top->next = head;

    struct ListNode *prev = top, *cur;
    while(prev->next!=NULL){
        cur = prev->next;
        if (cur->val == val){
            prev->next = cur->next;
            free(cur);
        }
        else{
            prev = prev->next;
        }
    }

    head = top->next;
    free(top);
    return head;
}
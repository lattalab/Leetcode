/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // find list A
    struct ListNode *curA = headA;
    int lenA = 0;
    while(curA != NULL){
        curA = curA->next;
        lenA++;
    }

    // find list B
    struct ListNode *curB = headB;
    int lenB = 0;
    while(curB != NULL){
        curB = curB->next;
        lenB++;
    }

    // find length gap
    curA = headA;
    curB = headB;
    if (lenA > lenB){
        int gap = lenA - lenB;
        while (gap--){
            curA = curA->next;
        }
    }
    else {
        int gap = lenB - lenA;
        while (gap--){
            curB = curB->next;
        }
    }

    // main logic
    while (curA != NULL){
        if (curA == curB) return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}
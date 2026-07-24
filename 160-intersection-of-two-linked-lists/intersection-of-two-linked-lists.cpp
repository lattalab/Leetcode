/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr = headA;
        // Traverse the listA
        int lenA = 0;
        while (curr) {
            curr = curr->next;
            lenA++;
        }

        // Traverse the listB
        curr = headB;
        int lenB = 0;
        while (curr) {
            curr = curr->next;
            lenB++;
        }

        // remove the gap
        ListNode *list1 = headA;
        ListNode *list2 = headB;
        if (lenA > lenB) {
            int gap = lenA - lenB;
            while (gap--) {
                list1 = list1->next;
            }
        }
        else {
            int gap = lenB - lenA;
            while (gap--) {
                list2 = list2->next;
            }
        }

        // traverse at the same time
        while (list1 && list2) {
            if (list1 == list2) {
                return list1;
            }
            list1 = list1->next;
            list2 = list2->next;
        }

        return nullptr;
    }
};
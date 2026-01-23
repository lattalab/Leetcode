/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // create a dummy head
        ListNode* dummy = (ListNode*) malloc(sizeof(ListNode));
        dummy->next = head;

        ListNode* cur = dummy;
        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode* first = cur->next;
            ListNode* second = cur->next->next; 
            // swap logic
            first->next = second->next; // 1->3
            second->next = first;       // 2->1
            cur->next = second;         // dummy-> new head (2)
            // update cur
            cur = cur->next->next;
        }
        head = dummy->next;
        free(dummy);
        return head;
    }
};
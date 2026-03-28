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
    ListNode* removeElements(ListNode* head, int val) {
        // create empty head
        ListNode* dummy = new ListNode();
        dummy->next = head;
        // main logic
        ListNode *prev = dummy;
        ListNode *cur = head;
        while (cur!= NULL) {
            
            if (cur->val == val) {
                ListNode *temp = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete temp;
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }

        // remove dummy head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // traverse the linked list and perfrom add
        ListNode *n1 = l1, *n2 = l2;
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        int carry = 0;
        
        // remember to update the pointer
        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum/10;
        }

        // delete dummy head
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};
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
    ListNode* deleteMiddle(ListNode* head) {
        // base case
        if (head == NULL || head->next == NULL) 
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;

        while (fast && fast->next) {
            prev = slow;        // predence of middle node
            slow = slow->next;  // pointer to middle node
            fast = fast->next->next;
        }

        // modify the linked;
        prev->next = slow->next;
        delete slow;
        return head;
    }
};
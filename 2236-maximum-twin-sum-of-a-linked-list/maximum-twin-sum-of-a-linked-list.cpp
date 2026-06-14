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
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;

        while (fast && fast->next) {
            fast = fast->next->next;
            // reverse half of linked list
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        ListNode *TwinLeft = prev;
        ListNode *TwinRight = slow;
        int ans = 0;
        while (TwinLeft) {
            int sum = TwinLeft->val + TwinRight->val;
            ans = max(ans, sum);
            TwinLeft = TwinLeft->next;
            TwinRight = TwinRight->next;
        }
        return ans;
    }
};
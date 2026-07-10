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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode *slow = head;
        ListNode *fast = head;
        // finding middle of linked list
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half of linked list
        ListNode *curr = slow;
        ListNode *prev = NULL;
        while (curr != NULL) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // finding the palindrome
        ListNode *h1 = prev;
        ListNode *h2 = head;
        while (h1 != NULL && h2 != NULL) {
            if (h1->val != h2->val) {
                return false;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        return true;
    }
};
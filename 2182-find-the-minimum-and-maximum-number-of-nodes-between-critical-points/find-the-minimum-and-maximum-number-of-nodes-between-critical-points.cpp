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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head->next || !head->next->next) return {-1, -1};

        ListNode *prev = head, *curr = head->next, *next=head->next->next;
        
        int first=-1, p=-1, n=-1;
        int idx = 1;
        int min_dist = INT_MAX, max_dist;
        while (next != NULL) {
            // find critical point
            if ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) {
                p = n;
                n = idx;

                // find the first critical
                if (first == -1) {
                    first = idx;
                }
                // try to find minimum distance
                if (p != -1) {
                    min_dist = min(min_dist, n-p);
                }
            }

            idx++;
            prev = prev->next;
            curr = curr->next;
            next = next->next;
        }

        // test if fewer than two critical point
        if (p == -1) min_dist = -1;
        max_dist = (p == -1) ? -1 : n - first;
        return {min_dist, max_dist};
    }
};
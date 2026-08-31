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
        // fewer than three node, no critical point
        if (!head->next || !head->next->next) return {-1, -1};

        // to examine the critical point,
        // we need current node, previous node, next node.
        ListNode *prev = head, *curr = head->next, *next=head->next->next;
        
        int firstCritical=-1, prevCritical=-1, nextCritical=-1;
        int idx = 1;    // keep track of current node
        int min_dist = INT_MAX;

        while (next != NULL) {
            // find critical point
            if ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) {
                
                // keep track of neighbor node
                prevCritical = nextCritical; 
                nextCritical = idx;

                // find the first critical
                if (firstCritical == -1) {
                    firstCritical = idx;
                }
                // try to find minimum distance
                if (prevCritical != -1) {
                    min_dist = min(min_dist, nextCritical - prevCritical );
                }

            }

            // increment
            idx++;
            prev = prev->next;
            curr = curr->next;
            next = next->next;
        }

        // test if fewer than two critical point
        if (prevCritical == -1)
            return {-1, -1};
        
        // the maximum is the lastest and first one critical point's distance
        int max_dist = nextCritical - firstCritical;
        return {min_dist, max_dist};
    }
};
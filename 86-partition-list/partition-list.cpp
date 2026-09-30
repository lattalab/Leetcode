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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        // create two linked list 
        // record the smaller value and bigger value
        ListNode *slist = new ListNode(0, NULL);
        ListNode *slist_tail = slist;
        ListNode *blist = new ListNode(0, NULL);
        ListNode *blist_tail = blist;
        
        // traverse the linked list
        ListNode *curr = head;
        while (curr) {
            if (curr->val < x) {
                // connect the smaller value
                slist_tail->next = curr;
                // move to next element
                curr = curr->next;
                // slist move
                slist_tail = slist_tail->next;
                // disconnect to original linked list
                slist_tail->next = NULL;
            }
            else {
                // connect the bigger value
                blist_tail->next = curr;
                // move to next element
                curr = curr->next;
                // blist move
                blist_tail = blist_tail->next;
                // disconnect to original linked list
                blist_tail->next = NULL;
            }
        }

        // connect two linked list
        slist_tail->next = blist->next;
        // release memory space
        ListNode *new_head = slist->next;
        delete slist;
        delete blist;

        return new_head;
    }
};
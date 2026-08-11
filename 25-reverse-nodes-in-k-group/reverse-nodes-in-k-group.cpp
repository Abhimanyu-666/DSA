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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: check if at least k nodes remain from `head`
        ListNode* node = head;
        int count = 0;
        while (node && count < k) {
            node = node->next;
            count++;
        }
        if (count < k) return head;   // fewer than k nodes left — leave as-is

        // Step 2: reverse the first k nodes of this segment
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // prev is now the new head of this reversed group
        // curr is the node right after this group (start of the rest of the list)

        // Step 3: recursively reverse the rest, then connect
        // `head` is now the TAIL of this reversed group (it was the original head)
        head->next = reverseKGroup(curr, k);

        return prev;   // new head of this group
    }
};
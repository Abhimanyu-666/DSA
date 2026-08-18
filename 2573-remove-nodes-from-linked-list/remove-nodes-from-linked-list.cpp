class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        // Step 1: reverse the list
        head = reverseList(head);

        // Step 2: single pass, remove nodes smaller than the running max seen so far
        ListNode* cur = head;
        int curMax = cur->val;

        while (cur->next != nullptr) {
            if (cur->next->val < curMax) {
                cur->next = cur->next->next; // skip / remove it
            } else {
                curMax = cur->next->val;
                cur = cur->next;
            }
        }

        // Step 3: reverse back to restore original order
        return reverseList(head);
    }
};
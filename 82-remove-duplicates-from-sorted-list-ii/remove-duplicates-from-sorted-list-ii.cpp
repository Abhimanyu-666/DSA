class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                int dupVal = cur->val;
                while (cur && cur->val == dupVal) {
                    cur = cur->next;
                }
                prev->next = cur;   // skip the whole duplicate run
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        ListNode* temp = head;
        while (temp) {
            sum = sum * 2 + temp->val;
            temp = temp->next;
        }
        return sum;
    }
};
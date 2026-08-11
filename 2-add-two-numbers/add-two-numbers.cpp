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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode*a = l1;
        ListNode*b = l2;    
        ListNode *c = new ListNode(0);
        ListNode *head = c;
        while (a or b) {
            int x = a ? a->val : 0;
            int y = b ? b->val : 0;
            int sum = x + y + carry;
            head->next = new ListNode(sum % 10);
            carry = sum / 10;
            head = head->next;
            if (a) a = a->next;
            if (b) b = b->next;
        }
        if (carry) head->next = new ListNode(carry);
        return c->next;

    }
};
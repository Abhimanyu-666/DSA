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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* d1 = new ListNode(10);
        ListNode* d2 = new ListNode(20);
        ListNode* t1 = d1;
        ListNode* t2 = d2;
        ListNode* temp = head;
        while(temp){
            t1->next = temp;
            temp = temp->next;
            t1 = t1->next;
            t2->next = temp;
            if(temp)temp = temp->next;
            if(t2)t2 = t2->next;
        }
        t1->next = d2->next;
        return d1->next;
    }
};
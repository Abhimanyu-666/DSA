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
    ListNode* reverse(ListNode* head){
        ListNode* next = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        long long sum = INT_MIN;
        int n =1;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        temp = head;
        for(int i=0 ; i<n/2 ; i++){
            temp = temp->next;
        }
        ListNode* a = reverse(temp);
        ListNode* td = a;
        temp = head;
        while(td){
            long long ele = (temp->val)+(td->val);
            sum  = max(sum,ele);
            temp = temp->next;
            td = td->next;
        }
        return sum;
    }
};
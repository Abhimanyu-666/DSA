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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp = head;
        int n=0;
        while(temp!=NULL){
            temp = temp->next;
            n++;
        }
        // breaking the list into k lists
        int size = n/k;
        int rem = n%k;
        temp = head;
        while(temp!=NULL){
            ListNode* c = new ListNode(10);
            ListNode* tc = c;
            int s= size;
            if(rem>0) s++;
            rem--;
            for(int i=1; i<=s ; i++){
                tc->next = temp;
                temp = temp->next;
                tc =  tc->next;
            }
            tc->next = NULL; 
            ans.push_back(c->next);   
        }
        if(ans.size()<k){
            while(ans.size()!=k){
                ans.push_back(NULL);
            }
        }
        return ans;
    }
};
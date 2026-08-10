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
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;  
            prev = curr;
            curr = next;  
        }
        return prev;

    }
     ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(left == right) return head;
        int n=1;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            if(n==(l-1)) a=temp;
            if(n==l) b=temp;
            if(n==r) c=temp;
            if(n==(r+1)) d=temp;
            n++;
            temp = temp->next;
        }
        if(a)a->next = NULL;
        if(c)c->next = NULL;
        c = reverse(b);
        if(a)a->next = c;
        b->next = d;

        if(a)return head;
        return c;
        
    
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while(temp && temp->next){
            int remlen =0;
            ListNode* t = temp->next;
            for(int i=1 ;i<=gap+1 && t!=NULL; i++){
                t = t->next;
                remlen++;
            }
            if(remlen < gap+1) gap = remlen-1;
            if(gap%2!=0)reverseBetween(temp,2,2+gap);
            gap++;
            for(int i=1 ; temp!=NULL && i<=gap ; i++){
                temp = temp->next;
            }
        }
        
        return head;

    }
};
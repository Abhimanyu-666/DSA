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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
       ListNode dummy(0, head);
        ListNode *prev = &dummy;
        ListNode *curr = head;
        int elem = 1;

       while(curr != nullptr){
         int len = 0;
         ListNode *count = curr;
         while(len < elem && count != nullptr){
            count = count->next;
            len++;
         }  
         
         int counter=1;
         if(len % 2 == 0){
           while(counter < len && curr->next != nullptr){
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next =prev->next;
            prev->next = temp;
            counter++;
           }
         }else{   
            while(counter < len && curr!=nullptr){
                curr = curr->next;
                counter++;
            } 
         }
         prev = curr;
         curr = curr->next;        
         elem++;      
       }
       return dummy.next;
    }
};
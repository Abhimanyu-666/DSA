class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(head->next == NULL) return head;
        ListNode* temp = head;
        vector<int> arr;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        vector<int> st;   // vecxtor implemented as stack because using stack the linked list will printed in reverse order
        for (int i = 0; i < n; i++) {
            while (st.size()>0 && st.back()<arr[i]) {
                st.pop_back();
            }
            st.push_back(arr[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* t = dummy;
        for (int i=0 ;i<st.size() ; i++) {
            t->next = new ListNode(st[i]);
            t = t->next;
        }
        return dummy->next;
    }
};
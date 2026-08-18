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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(arr[n-1]);
        ans[n-1] = 0;
        for(int i=n-2 ; i>=0 ; i--){
            // pop
            while(st.size()>0 && st.top()<=arr[i]) st.pop();

            /// ans
            if(st.size()==0) ans[i]=0;
            else ans[i] = st.top();

            // push
            st.push(arr[i]);
        }

        return ans;
    }
};
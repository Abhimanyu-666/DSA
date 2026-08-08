class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq;
        int n = arr.size();
        for(int i=0 ; i<n ; i++){
            pq.push(arr[i]);
        }
        while(pq.size()>0){
            if(pq.size()==1) return pq.top();
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int ele =abs(x-y);
            if(ele!=0) pq.push(ele);
        }
        return 0;
    }
};
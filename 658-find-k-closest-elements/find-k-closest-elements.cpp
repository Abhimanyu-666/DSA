class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pi> pq;
        int n=arr.size();
        
        for(int i=0 ; i<n ; i++){
            int dist = abs(x-arr[i]);
            pi p = {dist,arr[i]};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }

        while(pq.size()>0){
            int x = pq.top().second;
            ans.push_back(x);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        // map pair is <ele,freq>
        int n = arr.size();
        for(int i=0 ; i<n ; i++){
            map[arr[i]]++;
        } 
        // heap pair is <freq,ele>
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x : map){
            int ele = x.first;
            int freq = x.second;
            pair<int,int> p = {freq,ele};
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }

        return ans;
    }
};
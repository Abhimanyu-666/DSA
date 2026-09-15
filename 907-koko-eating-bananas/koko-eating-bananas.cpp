class Solution {
public:

    bool check(int speed,vector<int> arr, int h){
        int n = arr.size();
        int count=0;
        for(int i=0 ; i<n; i++){
            if(count > h) return false;
            if(speed >= arr[i]) count ++;
            else if(arr[i]%speed == 0) count += arr[i]/speed;
            else  count += arr[i]/speed + 1; /// very important
        }
        if(count > h) return false;
        else return true;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx = INT_MIN;
        for(int i=0 ; i<n ; i++){
            mx = max(mx,piles[i]);
        }
        int lo = 1;
        int hi = mx;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,piles,h) == true){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};
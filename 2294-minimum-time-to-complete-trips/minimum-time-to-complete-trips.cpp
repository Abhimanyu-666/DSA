class Solution {
public:
    bool check(long long mid, vector<int>& time, int totalTrips){
        long long trips = 0;
        for (int t : time){
            trips += mid / (long long)t;
            if (trips >= totalTrips) return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int mn = *min_element(time.begin(), time.end());
        long long lo = 1;
        long long hi = (long long)mn * (long long)totalTrips;
        long long ans = hi;

        while (lo <= hi){
            long long mid = lo + (hi - lo) / 2;
            if (check(mid, time, totalTrips)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};
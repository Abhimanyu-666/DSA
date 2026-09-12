class Solution {
public:
    int lowerBound(vector<int>& arr, int x){
        int lo = 0, hi = arr.size();  // note: hi = size(), not size()-1
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid] < x) lo = mid+1;
            else hi = mid;
        }
        return lo; // first index with arr[index] >= x (== size() if none)
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int first = lowerBound(arr, target);

        if(first == n || arr[first] != target) 
            return {-1, -1}; // target doesn't exist at all

        int last = lowerBound(arr, target+1) - 1;
        return {first, last};
    }
};
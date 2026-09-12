class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans(2, -1);
        int n = arr.size();
        int lo = 0, hi = n - 1;

        while (lo <= hi) { // first position
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) {
                if (mid == 0 || arr[mid - 1] != target) {
                    ans[0] = mid;
                    break;
                }
                else hi = mid - 1;
            }
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }

        lo = 0; hi = n - 1;
        while (lo <= hi) { // last position
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target) {
                if (mid == n - 1 || arr[mid + 1] != target) {
                    ans[1] = mid;
                    break;
                }
                else lo = mid + 1;
            }
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }

        return ans;
    }
};
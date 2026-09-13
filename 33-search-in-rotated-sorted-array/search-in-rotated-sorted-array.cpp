class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 1 3 4 6 8 20 28 33
        // 6 8 20 28 33 1 3 4
      int n= nums.size();
      int lo = 0;
      int hi = n-1;
      if(n==2){
        if(target==nums[0]) return 0;
        else if( target == nums[1]) return 1;        
        else return -1;
      }
      
      // finding the pivot idx;
      int pivot = -1 ;//smallest element
      
      while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(mid==0) lo = mid+1;
        else if(mid == n-1) hi = mid-1;
        else if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
            pivot = mid; 
            break;
        }
        else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
            pivot = mid+1; // mid is basically the largest element so store the smallest ele
            break;
        }
        else if(nums[mid]>nums[hi]){
            lo = mid +1;
        }
        
        else hi = mid-1;
        
      }
      if(pivot == -1) {// already sorted
        // pivot kabhi mila hi nahi
        int lo = 0;
        int hi = n-1;
        // normal binary search on full array
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
      }
      if(target>=nums[0] && target <=nums[pivot-1]){
        lo = 0;
        hi = pivot-1;
        // normal binary search
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target) lo = mid+1;
            else hi = mid-1;
        }
      }
      else {
        int lo = pivot;
        int hi = n-1;
        // normal binary search
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target) hi = mid-1;
            else lo = mid+1;
        }
      }
      return -1;
    }
};
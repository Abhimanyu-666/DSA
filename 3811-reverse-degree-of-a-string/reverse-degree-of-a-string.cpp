class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += (26 - (s[i] - 'a')) * (i+1);; // if s[i]=a -> 98 - 98 = 0
        }
        return sum;
    }
};
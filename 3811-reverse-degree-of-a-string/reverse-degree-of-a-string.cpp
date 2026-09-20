class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0 ; i<n ; i++){
            int revPos = 26 - (s[i] - 'a'); // if s[i]=a -> 98 - 98 = 0
            sum += revPos * (i+1);
        }
        return sum;
    }
};
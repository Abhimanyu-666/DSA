class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //sort both the arrays
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int m = g.size();// geerdy vector
        int n = s.size();// cookie vector

        int l = 0;
        int r = 0;

        while(l<n && r<m){
            if(g[r] <= s[l]) r = r+1; // it statisfy the child (enough cookies to satisfy)
            l = l+1; // move to the bext cookie wheather it satisy the child or not
        }
        return r;
    }
};
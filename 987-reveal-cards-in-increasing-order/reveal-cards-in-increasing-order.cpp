class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        queue<int> q;
        vector<int> ans(n);
        for(int i=0 ; i<n ; i++){
            q.push(i);
        }
        for(int i=0 ; i<n ; i++){
            int idx = q.front();
            q.pop();        // reveal the card
            q.push(q.front()); // put the card at th bottom
            q.pop();
            ans[idx] = deck[i]; 
        }
        return ans;
    }
};
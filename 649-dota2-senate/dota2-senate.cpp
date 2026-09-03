class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> q,r,d;
        for(int i=0 ; i<n ;i++){
            q.push(i);
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        int i=0;
        while(q.size()>1){
            if(senate[q.front()]== 'R'){
                if(d.size()>0){
                    senate[d.front()] = 'X';
                    d.pop();
                    // work is done
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
                else return "Radiant";
            }
            else if(senate[q.front()]=='X') q.pop();
            else{
                if(r.size()>0){
                    senate[r.front()] = 'X';
                    r.pop();
                    // work is done
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }
                else return "Dire";
            }
        }
        if(senate[q.front()]=='R') return "Radiant";
        else return "Dire";
    }
};
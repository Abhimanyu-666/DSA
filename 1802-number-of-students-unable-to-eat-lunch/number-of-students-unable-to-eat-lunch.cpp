class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int m = sandwiches.size();
        queue<int> q;
        for(int i=0 ;i<n ; i++){
            q.push(students[i]);
        }
        int i = 0; // to traverse the sandwich arrray
        int count = 0;
        while(q.size()>0 && count!=q.size()){
            if(q.front()==sandwiches[i]){
                count=0;
                q.pop();
                i++;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};
class Solution {
public:
    void sortColors(vector<int>& n) {
        int size = n.size();
         priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<size; i++){
           q.push(n[i]);
 
        }
        for(int i=0; i<size; i++){
           n[i] = q.top();
               q.pop();
        }
        
    }
};
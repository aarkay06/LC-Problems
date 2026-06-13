class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
    
        string ans;
        for (string s : words) {
            int weight = 0;
            for (char c : s) {
                weight += weights[c-'a'];
            }
            char res = 'z' - (weight % 26) ;
            ans += res;
        }
        return ans;
    }
};
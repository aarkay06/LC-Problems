class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            prefix[i] = prefix[i - 1]^arr[i];
        }
        
        vector<int> res(queries.size());
        
        for (int j = 0; j < queries.size(); j++) {
            int i = queries[j][0];
            int k = queries[j][1];
            if (i == 0) {
                res[j] = prefix[k];
            } else {
                res[j] = prefix[k] ^ prefix[i - 1];
            }
        }
        
        return res;
    }
};
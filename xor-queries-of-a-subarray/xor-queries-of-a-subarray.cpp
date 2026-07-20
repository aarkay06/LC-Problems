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

//xor of equal numbers is 0
//we know xor upto RIGHT and upto LEFT,
//to find the xor of numbers between them
//we have to remove the elements that came before LEFT
//RIGHT also contains xor of LEFT 
//RIGHT = LEFT ^ n1 ^ n2 ^ n3......
//LEFT = LEFT, xor(LEFT^LEFT) = 0
//RIGHT ^ LEFT = n1 ^ n2 ^ n3.....

                res[j] = prefix[k] ^ prefix[i - 1];
            }
        }
        
        return res;
    }
};
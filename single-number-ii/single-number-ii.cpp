class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                int num = nums[j] >> i;
                if (num & 1) {
                    sum++;
                }
            }
            bits.push_back(sum % 3);
        }
        int res = 0;
       
        for (int i = 0; i < bits.size()-1; i++) {
                res = res + (pow(2, i) * bits[i]);
        }
        if (bits[31] == 1) res = res- pow(2,31);
        return res;
   
    }
};

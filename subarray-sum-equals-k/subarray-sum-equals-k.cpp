class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for (int i = 1; i < nums.size(); i++) {
              nums[i] += nums[i-1];
        }

          unordered_map<int, int> m;
        int count =0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == k) count++;

            if(m.contains(nums[i] - k)){
                count += m[nums[i] -k];
            }

            m[nums[i]]++;
        }

        return count;


        
    }
};
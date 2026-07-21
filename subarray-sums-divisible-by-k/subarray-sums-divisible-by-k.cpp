class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
//4, 5, 0, -2, -3, 1
//4, 9, 9, 7, 4, 5
//4, 4, 4, 2, 4, 0

//when same remainders -> n & n + k, that means the number itself is divisible
//when 0 remainder then also a soultion
     for (int i = 1; i < nums.size(); i++) { nums[i] += nums[i - 1]; }

     //
     for (int i = 0; i < nums.size(); i++) {
          nums[i] = ((nums[i] % k) + k) %k;
     }

     unordered_map<int, int> m;
    int count = 0;
     for (int i = 0; i < nums.size(); i++) {
           if(nums[i] == 0) count++;

           if(m.contains(nums[i]))
           count += m[nums[i]];

           m[nums[i]]++;
     }

     return count;
    }
};
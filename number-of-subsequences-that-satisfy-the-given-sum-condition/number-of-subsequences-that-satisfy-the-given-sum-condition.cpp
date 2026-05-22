class Solution {
public:
     int m = 1e9 + 7;
    
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

    int numSubseq(vector<int>& nums, int target) {
    long long count = 0;
       sort(nums.begin(), nums.end());
       for(int i = 0; i < nums.size(); i++){
        if(2*nums[i] <= target) count = (count%m + 1%m) %m;

        if(nums[i] > target ) continue;

          int u =   upper_bound(nums.begin(), nums.end(), target-nums[i]) - nums.begin() -1;
          count = (count%m  + binpow(2, u-i, m) -1 ) %m;
       }
       return count;
    }
};
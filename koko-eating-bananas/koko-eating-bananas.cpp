class Solution {
public:

    bool isValid(vector<int>& nums, int h, int k){
        long long hrs=0;
        for(int i=0; i<nums.size(); i++){
            hrs += nums[i] / k;
            if(nums[i] % k != 0 ) hrs++; 
        }
        return hrs <= h;
        
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int min = 1;
        int max = *max_element(nums.begin(), nums.end());
        int ans;
        while(min <= max){
            int mid = (min+max)/2;
            if(isValid(nums, h, mid )){
                max = mid-1;
                ans = mid;
            }else{
                min = mid+1;
            }
        }
        return ans;
    }
};
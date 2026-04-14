class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum =0;
        int min =nums.size()+1;
        while (j < nums.size()) {
            if(sum + nums[j] >= target){
                if(j-i+1 < min){
                    min = j-i+1;
                }
                sum -= nums[i];
                i++;

            }else{
                sum+= nums[j];
                j++;
                
            }
        }
        cout << "sum: " << sum << ", min: " << min;
    if(min > nums.size() ) min =0;
        return min;
    }
};
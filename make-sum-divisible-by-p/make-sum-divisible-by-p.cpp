class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = nums[0];
        nums[0] = nums[0] % p;
        for (int i = 1; i < nums.size(); i++) {
           sum += nums[i];
           nums[i] = sum % p;
        }

        int n = nums.size() - 1;
        if (nums[n] == 0)
            return 0;

        else {
            // when we are at index i, we are trying to find the smallest
            // subarray thhat we can delete until that number so that the sum is
            // then divisble by k.

            // we have to subtract numbers such that the final remainder is 0
            // so if final remainder is 5, we have to delete (5 + k)

            // now ho do we know if a subarray (ending at current i) has a sum
            // of 5+k without iterating back to all elements?
            // By using the remainders we can figure out the subarray that we
            // could delete to make the final sum divisble

            // lets say we have an array of remainders,  4 4 1 3 6
            // When we are at index of rem == 3, we check the remainder of the
            // final sum, its 6 6 means that we have to delete numbers of sum ==
            // (nP + 6) Now when we are at rem == 3, how do we figure out the
            // starting index of the subarray which ends athhis index and has a
            // sum of (nP + 6)? Currently, including that subarray, the
            // remainder at this index is 3, and we have to delete this
            // subarray, and rem of this whole subarray should be 6 Therefore
            // right before the start of the subarray, we should have a
            // remainder of (3 - 6) -> (3 + k - 6) % k.

            // When remainder before the subarray is 4, (4+6) % 3 == 3 simple

            // vector<int> rems(p + 1, -1);
            unordered_map<int, int> m;
            int minimum = INT_MAX;
            for (int i = 0; i < nums.size(); i++) {
                int currRem = nums[i];
                int finalRem = nums[nums.size() - 1];
                int targetRem = (currRem + p - finalRem) % p;

                // case 1, if the rem of the prefix at index i is 6, the final
                // remainder is also 6
                //  so we have to delete any sum with remainder 6
                //  our targetRem here would be 0
                // if 0 doesnt already exist, we will the whole subarray as the
                // min len

                //   if(targetRem == 0 && rems[0] == -1){
//                        minimum = min(minimum, i +1 );
//                 } 


//                 if (rems[targetRem] != -1) {
//                     minimum = min(minimum, i - rems[targetRem] );
//                 }
//                 rems[currRem] = i;

                if (targetRem == 0 && !m.contains(0)) {
                    minimum = min(minimum, i + 1);
                }

                if (m.contains(targetRem)) {
                    minimum = min(minimum, i - m[targetRem]);
                }
                m[currRem] = i;


                
            }

            if (minimum == nums.size())
                minimum = INT_MAX;
            return minimum == INT_MAX ? -1 : minimum;
        }
    };
};

class Solution
{
public:
    unordered_map<string, int> map;

    int split_subarray(vector<int> &nums, vector<int> &prefix, int k, int start, int end)
    {
        //  Return the value if it already exists
        // If it doesnt, we'll save it before returning
        string main_key =
            to_string(k) + "," + to_string(start) + "," + to_string(end);
        if (map.find(main_key) != map.end())
            return map[main_key];

        // If there's only a single element, return it
        if (start == end)
        {
            map[main_key] = nums[start];
            return nums[start];
        }

        if (k == 1) {
            int sum = (start == 0) ? prefix[end] : prefix[end] - prefix[start - 1];
            map[main_key] = sum;
            return sum;
        }

        // // Find a Mid for it
        // int mid = (start + end) / 2;
        // // If there are not enough elements for on the 2nd part of the array,
        // // that is after mid, then we decrease the mid until there is.
        // while (!(end - mid >= k))
        // {
        //     mid--;
        // }

        // This variable will store the max value of all subarrays that exist within it.
        int max_sum;



        int low = start;
        int high = end - (k - 1); 

        //Variable to store the max possible sum of any subarray from this array.
        int best_ans = INT_MAX; 

         while (low <= high) {
            int mid = low + (high - low) / 2;
        
            //Sum of the subarray upto left
            int left_sum = (start == 0) ? prefix[mid] : prefix[mid] - prefix[start - 1];
            
            //Max sum of all subarrays on the right of mid
            //Check if it already exists in the map
            //If yes, use it. if not calculate it and store it.
            string sub_key = to_string(k - 1) + "," + to_string(mid + 1) + "," + to_string(end);
            int right_sum;
            
            if (map.find(sub_key) != map.end()) {
                right_sum = map[sub_key];
            } else {
                right_sum = split_subarray(nums, prefix, k - 1, mid + 1, end);
                map[sub_key] = right_sum;
            }
            
            //Max sum for this mid
            int current_max = max(left_sum, right_sum);
            
            //Check if this max sum is lower than min sums we've seen before.
            best_ans = min(best_ans, current_max);
            
            //Go left if left is heavier
            if (left_sum > right_sum) {
                high = mid - 1;
            }
            //right is heavier
             else if (left_sum < right_sum) {
               
                low = mid + 1;
            } else {

                break; 
            }
        }
        
        // Save beofre returning
        map[main_key] = best_ans;
        return best_ans;

    }

    int splitArray(vector<int> &nums, int k)
    {
        map.clear();
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
         prefix[i] = nums[i] + prefix[i - 1];
        }
        int minimum_sum = split_subarray(nums, prefix, k, 0, nums.size() - 1);
        return minimum_sum;
    }
};
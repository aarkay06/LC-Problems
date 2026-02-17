class Solution {
public:
    bool isValid(vector<int>& candies, long long k, long long mid) {
        long long c = 0;
        if (mid == 0)
            return k;
        for (int candy : candies)
        {
            c += ((long long)candy / mid);
        }
        return c >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long min = 0;
        long long max = *max_element(candies.begin(), candies.end());
        // if(accumulate(candies.begin(), candies.end(), 0) < k) return 0;
        long long  valid_candies = 0;
        while (min <= max) {
            long long mid = (min + max) / 2;
            if (isValid(candies, k, mid)) {
                valid_candies =(int) mid;
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return (int) valid_candies;
    }
};
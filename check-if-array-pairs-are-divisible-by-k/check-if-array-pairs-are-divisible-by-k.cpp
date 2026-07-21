class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // 8 + 2
        // 3 + 2
        // 5

        // 2 2 2 4
        //  2 2 2 0

        vector<int> remainders(k);

        for (int i = 0; i < arr.size(); i++) {
            int rem = ((arr[i] % k) + k) % k;
            remainders[rem]++;
        }

        for (int i = 0; i < remainders.size(); i++) {
            if (remainders[i] == (remainders[((k - i) % k + k) % k])) {
                if (i == ((k - i) % k + k) % k && remainders[i] % 2 != 0)
                    return false;

                continue;
            } else
                return false;
        }

        return true;
    }
};
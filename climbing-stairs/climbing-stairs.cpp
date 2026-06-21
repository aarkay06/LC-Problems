class Solution {
public:
    int climbStairs(int num) {
        if (num == 1)
            return 1;
        if (num == 2)
            return 2;
        int m = 1;
        int n = 2;

        for (int i = 2; i < num; i++) {
            int temp = n;
            n = m + n;
            m = temp;
        }

        return n;
    }
};
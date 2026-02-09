class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);

        for (int i = 0; i < n + 1; i++)
        {
            long long count = 0;
            int temp = i;
            while (temp > 0)
            {
                if ((temp & 1) == 1)
                {
                    count++;
                }
                temp = temp >> 1;
            }
            ans[i] = count;
        }
        return ans;
    }
};

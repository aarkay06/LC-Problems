class Solution {
public:
  

    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> f(26);
        for (int i = 0; i < n; i++) {
            f[s[i] - 'a']++;
        }

        string r;
        char oddChar = '.';

        for (int i = 0; i < 26; i++) {
            if (f[i] % 2 != 0) {
                oddChar = 'a' + i;
            }

            f[i] = f[i] / 2;
            while (f[i] > 0) {
                r.push_back(i + 'a');
                f[i]--;
            }
        }

        string t = r;
         reverse(r.begin(), r.end());
        if(oddChar != '.'){
            t  += oddChar;
        }

        t += r;
        return t;
    }
};
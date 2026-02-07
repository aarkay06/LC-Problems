class Solution {
public:
    int characterReplacement(string s, int m) {
        int i = 0, j = 0, maxfreq = 0, len = 0;
        vector<int> freq(26, 0);
        for (; j < s.size();) {
            freq[(s[j] - 'A')]++;
            maxfreq = max(maxfreq, freq[(s[j] - 'A')]);
            cout << (s[j] - 'A') << endl;
            if ((j - i + 1) - maxfreq <= m) {

                len = max(j - i + 1, len);
                j++;
            } else {
                freq[(s[i] - 'A')]--;
                i++;
                j++;
            }
        }

        return len;
    }
};

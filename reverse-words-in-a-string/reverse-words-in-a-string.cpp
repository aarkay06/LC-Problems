class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        reverse(s.begin(), s.end());
        string word;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (word.length() > 0) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }

        if (word.length() > 0)
            words.push_back(word);
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            reverse(str.begin(), str.end());
            if (i != 0) {
                ans += (" " + str);
            } else {
                ans += str;
            }
        }
        return ans;
    }
};
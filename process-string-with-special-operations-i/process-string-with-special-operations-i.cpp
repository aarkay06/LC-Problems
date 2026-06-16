class Solution {
public:
    string processStr(string s) {
        string result = "";
        int i = 0;
        int j = s.size() - 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                result += s[i];
            else if (s[i] == '*') {
                if (result.size() > 0)
                    result.pop_back();
            }

            else if (s[i] == '#')
                result += result;

            else if (s[i] == '%')
                reverse(result.begin(), result.end());
        }

        return result;
    }
};
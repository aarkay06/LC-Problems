class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            int val;
            if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
                if(stk.empty()) return false;
                val = s[i];
                int top = stk.top();
                stk.pop();
                if ((val == 41 && top != 40) || (val == 93 && top != 91) ||
                    (val == 125 && top != 123))
                    return false;
            } else {
                stk.push(s[i]);
            }
        }
        return (stk.empty());
    }
};
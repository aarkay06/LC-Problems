class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 0;

        char lastChar = chars[0];
        int currLen = 1;
        int i = 0;
        int j = 1;
        while (j < chars.size()) {
            if (chars[j] == lastChar) {
                currLen++;
                j++;
            } else {

                if (currLen == 1) {
                    chars[i] = lastChar;
                    i++;
                    currLen = 0;
                    lastChar = chars[j];

                    len++;
                }
                if (currLen > 1) {
                    string str = to_string(currLen);

                    chars[i] = lastChar;
                    i++;
                    for (char x : str) {
                        chars[i] = x;
                        i++;
                    }
                    len += (str.size() + 1);
                    currLen = 0;
                    lastChar = chars[j];
                }
            }
        }

        if (currLen == 1) {
            chars[i] = lastChar;
            i++;
            currLen = 0;
            lastChar = chars[j];
            len++;
        }
        if (currLen > 1) {
            string str = to_string(currLen);
            chars[i] = lastChar;
            i++;
            for (char x : str) {
                chars[i] = x;
                i++;
            }
            len += (str.size() + 1);
            currLen = 0;
            lastChar = chars[j];
        }
        return len;
    }
};
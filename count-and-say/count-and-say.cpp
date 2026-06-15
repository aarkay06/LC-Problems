class Solution {
public:

    string rle(string word){
         string comp = "";
        char lastChar = word[0];
        int currLen = 1;
        int j = 1;
        while (j < word.size()) {
            if (word[j] == lastChar && currLen < 9) {
                currLen++;
                j++;
            } else {
                char str = currLen + '0';
                comp.push_back(str);
                comp.push_back(lastChar);
                currLen = 0;
                lastChar = word[j];
            }
        }

            char str = currLen + '0';
            comp.push_back(str);
            comp.push_back(lastChar);
            currLen = 0;
            lastChar = word[j];

        return comp;
    }

    string countAndSay(int n) {
       if(n == 1) return "1";

        string s = countAndSay(n-1);
        return rle(s);
    }
};
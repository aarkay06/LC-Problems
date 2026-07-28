class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sF1(26);
        vector<int> sF2(26);

        for (int i = 0; i < s.size(); i++) {
              sF1[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
              sF2[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(sF1[i]!= sF2[i]) return false;
        }

        return true;
    }
};
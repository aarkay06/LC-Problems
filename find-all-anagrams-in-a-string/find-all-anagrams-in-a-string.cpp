class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> ans;
         if (s2.length() < s1.length())
            return ans;
        vector<int> arr(26);
        for (char c : s1) {
            arr[c - 'a']++;
        }

        int start = 0;
        int end = s1.length() - 1;

        vector<int> arr2(26);
        for (int i = 0; i < s1.length(); i++) {
            arr2[s2[i] - 'a']++;
        }
        if (matchArray(arr, arr2))
             ans.push_back(start);
        while (end < s2.length()-1) {
            arr2[s2[start] - 'a']--;

            start++;
            end++;
            arr2[s2[end] - 'a']++;

            if (matchArray(arr, arr2))
               ans.push_back(start);
        }

        return ans;
    }

        bool matchArray(vector<int> arr, vector<int> arr2) {
        for (int i = 0; i < 26; i++) {
            if (arr[i] != arr2[i])
                return false;
        }
        return true;
    };
};
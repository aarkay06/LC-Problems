class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
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
            return true;
        while (end < s2.length()-1) {
            arr2[s2[start] - 'a']--;

            start++;
            end++;
            arr2[s2[end] - 'a']++;

            if (matchArray(arr, arr2))
                return true;
        }

        return false;
    }

    bool matchArray(vector<int> arr, vector<int> arr2) {
        for (int i = 0; i < 26; i++) {
            if (arr[i] != arr2[i])
                return false;
        }
        return true;
    };
};
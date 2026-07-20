class Solution {
public:

    bool vowelCheck(string & str){
        return (
            (str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u')
            && 
            (str[str.size() -1] == 'a' || str[str.size() -1] == 'e' || str[str.size() -1] == 'i' || str[str.size() -1] == 'o' || str[str.size() -1] == 'u')
        );
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size());

        //first check for the first element
        if(vowelCheck(words[0])) prefix[0] = 1;

        for (int i = 1; i < words.size(); i++) {
              if(vowelCheck(words[i])) prefix[i] = prefix[i-1] +1;
              else prefix[i] = prefix[i-1];
        }

        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
              int start = queries[i][0];
              int end = queries[i][1];

            if(start == 0) 
            res[i] = prefix[end];
            else res[i] = prefix[end] - prefix[start-1];
        }

        return res;
    }
};
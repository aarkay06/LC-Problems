class Solution {
public:
bool isalphanum(char ch){
            if(ch>='0' && ch<='9') return true;
            if(ch>='a' && ch<= 'z') return true;
            return false;
        }
    bool isPalindrome(string s) {
        int st=0;
        int e= s.length()-1;
       for (char &c : s) {
        c = std::tolower((unsigned char)c);
    }
        while(st<e){
            if(!isalphanum(s[st])){
                st++;
                continue;
            }
            if(!isalphanum(s[e])){
                e--;
                continue;
            }
            if(s[st]!= s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
};
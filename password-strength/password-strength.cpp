class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char, int> set;
        int str = 0;
        for(char x: password){
            if(!set.contains(x)){
                set[x] = 1;
                if(x >= 'a' && x <= 'z') str++;
                else if(x >= 'A' && x <= 'Z') str += 2;
                else if(x >= '0' && x <= '9') str += 3;
                else if(x=='!' || x == '@' || x== '#' || x == '$') str += 5;
            }
        }
        return str;
    }
};
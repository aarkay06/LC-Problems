class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> arr(26);
        //0 ->  No occurence
        //1 ->  Lowercase only yet
        //2 ->  found an uppercase  
        //3 ->  turned from 1 to 3 or 2 to 3 -> Invalid

        for(char x: word){
            if(x >= 'a' && x <= 'z'){
                if(arr[x-'a'] == 0) arr[x-'a'] = 1;
                if(arr[x-'a'] == 2) arr[x-'a'] = 3;
            }else{
                 if(arr[x-'A'] == 0) arr[x-'A'] = 3;
                if(arr[x-'A'] == 1) arr[x-'A'] = 2;
            }
        }

        int count = 0;
        for(int x: arr){
            if(x == 2) count++;
        }
        return count;
    }
};
class Solution {
public:
    string removeOccurrences(string s, string part) {
    while(s.contains(part)){
          int found = s.find(part);
          s.erase(found, part.length());
    }

    return s;}
};
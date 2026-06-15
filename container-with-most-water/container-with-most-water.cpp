class Solution {
public:
    int maxArea(vector<int>& h) {
        int i =0;
        int j = h.size()-1;
        long long area = 0;
        while(i <= j){
            long long localArea = min(h[i], h[j]) * (j-i);
            area = max(area, localArea);
            if(h[i] >= h[j]) j--;
            else i++;
        }

        return area;
    }
};
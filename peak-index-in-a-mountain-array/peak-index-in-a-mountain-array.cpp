class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

     for(int i=0;i<arr.size(); i++){
        if(i == arr.size() -1 )return i;
        if(arr[i] >= arr[i+1]) return i;

     }   
     return arr.size()-1;
    }
};
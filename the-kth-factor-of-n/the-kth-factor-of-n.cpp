class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> arr1;
        vector<int> arr2;

        for (int i = 1; i*i <= n; i++) {
              if(n % i == 0){
                arr1.push_back(i);
                if(i*i != n)  arr2.push_back(n/i);
              }
        }
        int s1 = arr1.size();
        int s2 = arr2.size();
        if(k <= s1) return arr1[k-1];
        k -= s1;
        if( k <= s2 ) return arr2[s2-k];

        return -1;
    }
};
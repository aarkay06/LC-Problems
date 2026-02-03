class Solution {
public:

    double func(double x,long int n,double ans){
        if(n<0){
            n = -n;
            x = 1/x;
        }
        if(n == 1) return x;
        if(n == 0) return 1;
        if(n%2 != 0) {
           return x*func(x*x,n/2,ans);
        }
        return func(x*x,n/2,ans);
    }

    double myPow(double x, int n) {
        long int num =n;
        double ans = 1;
        return func(x,num,ans);
    }
};
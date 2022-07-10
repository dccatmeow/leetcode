class Solution {
public:
    int fib(int n) {
        if (n==0){
            return 0;
        }else if (n==1){
            return 1;
        }
        int pre2=0;
        int pre = 1;
        int res;
        for(int i=2; i<=n; ++i){
            res = pre+ pre2;
            pre2 = pre;
            pre = res;
        }
        return res;
    }
};

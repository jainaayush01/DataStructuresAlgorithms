// https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        if(n == 2) return n - 1;
        int a = 0, b = 1, c = 1, tn;
        for(int i = 3; i <= n; ++i) {
            tn = a + b + c;
            a = b; b = c; c = tn;
        }
        return tn;
    }
};

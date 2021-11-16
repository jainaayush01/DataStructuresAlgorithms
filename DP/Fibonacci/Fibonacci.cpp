// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, c;
        if(n < 2) return n;
        for(int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

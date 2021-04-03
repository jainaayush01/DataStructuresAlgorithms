// 1387 https://leetcode.com/problems/sort-integers-by-the-power-value/

int power[1001] = { 0, 0, 0 };
class Solution {
public:
    // Precalculate all the values before hand as total numbers are less and it will
    // take a lot of time to calcuate it for each testacase
    // and then its easy to sort them out
    
    int getPower(int i) {
    return i < 2 ? 0 :
        1 + (i % 2 ? getPower(i * 3 + 1) : getPower(i / 2));
    }
    
    int getKth(int lo, int hi, int k) {
        if (power[2] == 0) {
            for (auto i = 2; i <= 1000; ++i) {
                power[i] = getPower(i);
            }
        }
        
        int n = hi - lo + 1;
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; ++i) {
            arr[i].first = power[lo+i];
            arr[i].second = lo+i;
        }
        
        sort(arr.begin(), arr.end());
        return arr[k-1].second;
    }
};
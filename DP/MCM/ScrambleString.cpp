class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string a, string b) {
        int m = a.size(), n = b.size();
        if(m != n) {
            return false;
        }
        if(a.compare(b) == 0) {
            return true;
        }
        if(m <= 1) {
            return false;
        }
        string key = a;
        key += " " + b;

        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        for (int i = 1; i < n; ++i) {
            bool cond1 = isScramble(a.substr(0, i), b.substr(n-i, i)) && isScramble(a.substr(i, n-i), b.substr(0, n-i));
            bool cond2 = isScramble(a.substr(0, i), b.substr(0, i)) && isScramble(a.substr(i, n-i), b.substr(i, n-i));

            if(cond1 || cond2) {
                return mp[key] = true;
            }
        }
        return mp[key] = false;
    }
};
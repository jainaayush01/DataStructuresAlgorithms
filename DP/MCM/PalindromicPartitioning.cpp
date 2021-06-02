class Solution{
public:
    int dp[502][502]; // var changed i and j and are size of arr
    bool isPalindrome(string s, int b, int e) {
        int i = b, j = e;
        while( i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    int cuts(string str, int i, int j) {
        if(i >= j) {
            return 0;
        }
        if(isPalindrome(str, i, j)) {
            return dp[i][j] = 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k < j; ++k) {
            // tempans = cuts to make both stings palindrome + 1 for the cut
            dp[i][k] = (dp[i][k] == -1) ? cuts(str,i,k) : dp[i][k];
            dp[k+1][j] = (dp[k+1][j] == -1) ? cuts(str,k+1,j) : dp[k+1][j];
            int tempAns = dp[i][k] + dp[k+1][j] + 1;
            ans = min(tempAns, ans);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        int N = str.size();
        memset(dp, -1, sizeof(dp));
        int ret = cuts(str, 0, N-1);
        return ret;
    }
};
// still in this solution to optiize further u need to store palindrome for easy substring possible
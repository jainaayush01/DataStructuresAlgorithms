class Solution{
public:
    int dp[201][201][2]; // var changed i and j and are size of arr
    int solve(string str, int i, int j, int isTrue) {
        if(i > j) {
            return 0;
        }
        if(i == j) {
            if(isTrue) {
                return str[i] == 'T';
            }
            else {
                return str[i] == 'F';
            }
        }
        if(dp[i][j][isTrue] != -1) {
            return dp[i][j][isTrue];
        }
        int ans = 0;
        for(int k = i + 1; k < j; k += 2) {
            if(dp[i][k-1][1] == -1) {
                dp[i][k-1][1] = solve(str, i, k-1, 1);
            }
            if(dp[i][k-1][0] == -1) {
                dp[i][k-1][0] = solve(str, i, k-1, 0);
            }
            if(dp[k+1][j][1] == -1) {
                dp[k+1][j][1] = solve(str, k+1, j, 1);
            }
            if(dp[k+1][j][0] == -1) {
                dp[k+1][j][0] = solve(str, k+1, j, 0);
            }
            int lT = dp[i][k-1][1];
            int lF = dp[i][k-1][0];
            int rT = dp[k+1][j][1];
            int rF = dp[k+1][j][0];
            
            // int lT = solve(str, i, k-1, true);
            // int lF = solve(str, i, k-1, false);
            // int rT = solve(str, k+1, j, true);
            // int rF = solve(str, k+1, j, false);
            // dp[i][k-1][0] = lF;
            // dp[i][k-1][1] = lT;
            // dp[k+1][j][0] = rF;
            // dp[k+1][j][1] = rT;
            
            if(str[k] == '&') {
                if(isTrue) {
                    ans += (lT * rT);
                }
                else {
                    ans += (lF * rF) + (lF * rT) + (lT * rF);
                }
            }
            else if(str[k] == '|') {
                if(isTrue) {
                    ans += (lT * rT) + (lF * rT) + (lT * rF);
                }
                else {
                    ans += (lF * rF);
                }
            }
            else if(str[k] == '^') {
                if(isTrue) {
                    ans += (lT * rF) + (lF * rT);
                }
                else {
                    ans += (lT * rT) + (lF * rF);
                }
            }
            ans %= 1003;
        }
        return (dp[i][j][isTrue] = ans)%1003;
    }
    int countWays(int N, string str)
    {
        memset(dp, -1, sizeof(dp));
        int ret = solve(str, 0, N-1, 1);
        // for(int i = 0; i <= N; ++i) {
        //     for(int j = 0; j <= N; ++j) {
        //         cout << dp[i][j][0] << " " << dp[i][j][1] << endl;
        //     }
        //     cout<<endl;
        // }
        return ret%1003;
    }
};
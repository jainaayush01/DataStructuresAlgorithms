# Dynamic Programming Notes

## Where dp can be used?
> 1. Choice is given
> 2. Find optimal solution

## How to solve dp problems
> 1. Recursion
> 2. Recursion + Memoization
> 3. Top down approach
> 4. Bottom up approach

## 3 things to form a recursive approach
1. Base Condition -> think of the smallest valid input
2. Choice Diagram -> what choices can you make when you take any element.
3. How to make the next input smaller

## If any 2 of below properties match any other type of dp question than it can be solved using that technique (mostly in lcs)
1. I/P is similar 
2. What question is asking (minimum, maximum, etc);
3. O/P is similar

## types of dp problems
1. 01 knapsack(6)
2. Unbounded knapsack(5)
3. Fibonacci(7)
4. Longest Common Subsequence - LCS(15)
5. LIS(10)
6. Kadane's Algorithm(6)
7. Matrix chain multiplication(7)
8. DP on Tress(4)
9. DP on Grid(14)
10. Others(5)


# 1. 01 knapsack
[Link](https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/)
### Input:

```
wt[]: array of weights available

val[]: value of the subsequent weight 

N: number of weights

capacity/sum: maximum sum of weights knapsack can hold
```

### Problem:

```
choose the weight once or leave it
optimal: choose weights with maximum value with total weight less than given weight/sum
```

### Recursive Approach:
* Base Condition
    * Smallest valid input: when there is no element in the array or the total capacity of knapsack is 0.
* Choice Diagram:
    * If the weight of element is less than remaining capacity of knapsack?
        * Yes then i have 2 choices to include it or not.
        * No then i can't include it.
* Next Smaller Input: 
    * Once the choice on element is made we don't need it so we can reduce size of N

<!-- ### Recursive Code:

```
    int knapsack(int wt[], int val[], int N, int cap) {
        if(N == 0) {
            return 1;
        }
        if(cap <= 0) {
            return 0;
        }
        if(wt[N-1] <= cap) { 
            return knapsack(wt, val, )
        }
    }
``` -->

### Code:

```
    int knapsack01(int N, vector<int> wt, vector<int> val, int sum) {
        int dp[N+1][sum+1];
        // initialization
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= sum; ++i) {
            dp[0][i] = 0;
        }
        for(int i = 0; i <= N; ++i) {
            for(int j = 0; j <= sum; ++j) {
                if(wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
```

### How to identify Knapsack Problems:
* You have to choose for each element if you want to perform an operation on it or not.
* You have a capacity / maximum value 

### Practice problems similar to 01 knapsack.
1. [Subset sum](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/)
2. [Equal Subset sum partition problem](https://www.geeksforgeeks.org/partition-problem-dp-18/)
3. [Count of subset sum with a given sum](https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/)
4. [Minimum subset sum difference](https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/)
5. [count the number of subsets with a given difference]()
6. [target sum problem](https://leetcode.com/problems/target-sum/)

NOTE: Solutions are for your reference and are available in the DP subsequent folder

# 2. Unbounded knapsack

### Input:

```
wt[]: array of weights available

val[]: value of the subsequent weight 

N: number of weights

capacity/sum: maximum sum of weights knapsack can hold
```

### Problem:
[Link](https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/)

```
you can choose the weight multiple times or leave it
optimal: choose weights with maximum value with total weight less than given weight/sum
```

### Recursive Approach:
* Base Condition
    * Smallest valid input: when there is no element in the array or the total capacity of knapsack is 0.
* Choice Diagram:
    * If the weight of element is less than remaining capacity of knapsack?
        * Yes then i have 2 choices to include it(and then check for same element again) or not.
        * No then i can't include it.
* Next Smaller Input: 
    * Once the choice on element is made we don't need it so we can reduce size of N

### Code:

```
    int unboundedKnapsack(int N, vector<int> wt, vector<int> val, int sum) {
        int dp[N+1][sum+1];
        // initialization
        for(int i = 0; i <= N; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= sum; ++i) {
            dp[0][i] = 0;
        }
        for(int i = 0; i <= N; ++i) {
            for(int j = 0; j <= sum; ++j) {
                if(wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]); // only change than 01 knapsack
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
```

### Practice problems with similar to Unbounded knapsack
1. [Rod Cutting Problems](https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#)
2. [Coin Change Problem: Max ways](https://www.geeksforgeeks.org/coin-change-dp-7/)
3. [Coin Change Problem: Min coins](https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/)

NOTE: Solutions are for your reference and are available in the subsequent Folder


# 3. Longest Common Subsequence

### Problem:
[Link](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/)

```
Find the longest common subsequence which is common in the given two strings x and y
```

### Input:

```
x: string x of chars

y: string y of chars

```

Example I/P and O/P:
```
I/P:
    x: abcdgh
    y: abedfhr
O/P: 
    string: abdh 
    length: (4)

```

### Recursive Approach:
* Base Condition
    * Smallest valid input: When size of any 1 string is 0 then the lcs length will be zero.
* Choice Diagram:
    * If the last element of both string matches then we remove last element of both and add 1 to return length
    * else we have 2 choices and we take max of both the lengths
        1. m -> m-1 n -> n
        2. m -> m, n -> n-1
* Next Smaller Input: 
    * Once the choice on element is made we will make a choice so that we don't need to visit it again.

### Recusrsive Code:

```
    int longestCommonSubsequence(string x, string y, int m, int n) {
        // Base Condition
        if(m == 0 !! n == 0) {
            return 0;
        }
        // Choices
        if(x[m-1] == y[n-1]) {
            return 1 + longestCommonSubsequence(x, y, m-1, n-1);
        }
        else {
            return max(longestCommonSubsequence(x, y, m-1, n), longestCommonSubsequence(x, y, m, n-1));
        }
    }
    Memoized: 
    
```

### Recursion + Memoization:
```
    int static dp[1001][1001];
    memset(dp, -1, sizeof(dp)); <- in main 
    int longestCommonSubsequence(string x, string y, int m, int n) {
        // Base Condition
        if(m == 0 !! n == 0) {
            return 0;
        }
        // Choices
        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        if(x[m-1] == y[n-1]) {
            return dp[m][n] = 1 + longestCommonSubsequence(x, y, m-1, n-1);
        }
        else {
            return dp[m][n] = max(longestCommonSubsequence(x, y, m-1, n), longestCommonSubsequence(x, y, m, n-1));
        }
    }
```

### Top down Code:
```
    int longestCommonSubsequence(string x, string y, int m, int n) {
        int dp[m+1][n+1];
        for(int i = 0; i <= m; ++i) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(x[i-1] == y[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // to print lcs string
        string ans = "";
        int i = m, j = n;
        while( i > 0 && j > 0 ) {
            if(x[i-1] == t[j-1]) {
                ans += x[i - 1];
                i--;
                j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    i = i - 1;
                }
                else {
                    j = j - 1;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return dp[m][n];
    }
```

### Identification of LCS problems
* dynamic programming (Choice Optimal)
* 2 Strings are given
* We have to find longest common something OR optimal

### Can be solved using lcs?
1. I/P: 2 Strings (also sometimes if 1 can be used to make another hidden string)
2. Question: Longest
3. O/P: length (int)

### Practice problems with similar to Longest Common Subsequence
1. [Longest Common Substring](https://www.geeksforgeeks.org/longest-common-substring-dp-29/)
2. [Print Longest Common Subsequence](https://www.geeksforgeeks.org/printing-longest-common-subsequence/)
3. [Shortest Common SuperSequence](https://www.geeksforgeeks.org/shortest-common-supersequence/)
4. [Minimum Number of Insertion / Deletions to transform X to Y](https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/)
5. [Largest Palindromic Subsequence](https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/) | [LeetCode](https://leetcode.com/problems/longest-palindromic-subsequence/)
6. [Minimum Deletions to Make a String Palindromic](https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/)
7. [Print Shortest Common SuperSequence](https://www.geeksforgeeks.org/print-shortest-common-supersequence/) | [LeetCode](https://leetcode.com/problems/shortest-common-supersequence/)
8. [Largest Repeating Subsequence](https://www.geeksforgeeks.org/longest-repeated-subsequence/)
9. [Is Subsequence](https://www.geeksforgeeks.org/given-two-strings-find-first-string-subsequence-second/) | [LeetCode](https://leetcode.com/problems/is-subsequence/)
10. [Minimum Number of Insertions to make a String Palindromic](https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/)
11. [Length of largest subsequence of A which is substring in B](https://www.geeksforgeeks.org/find-length-longest-subsequence-one-string-substring-another-string/)
12. [Count how many times A appears as subsequence in B](https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/)
13. [Longest palindromic substring](https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/) | [LeetCode](https://leetcode.com/problems/longest-palindromic-substring/)
14. [Count of palindromic substring](https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/) | [LeetCode](https://leetcode.com/problems/palindromic-substrings/)

NOTE: Solutions are for your reference and are available in the subsequent Folder


# 4. Matrix Chain Multiplication

### Problem:
[Link](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)


Example I/P and O/P:
```
I/P: Array or String
    arr[]: [10, 20, 30, 40]
    Matrix dimensions are:
    AI = arr[i-1] * arr[i];
    bcuz [to multiply matrix n1 == m2]

O/P: Find Minimum Cost of multiplying the matrix with given dimensions
where cost of multipying matrix with dimenion m1,n1 and m2,n2 is given by arr[m1] * arr[n1] * arr[n2];

```

### Recursive Approach:
1. Find i, j
2. Find Base Condition
    * Think of first invalid Input: (i > j) return 0
3. We have to take i and j 
4. Loop k from i to j then call function on i = i and j = k and 2nd call on i = k+1 j = j
5. and then we calcuate ans from tempAns of the each loop


### Recursive Code:
```
    int solve(int arr[], int i, int j) {
        if(i >= j) {
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i; k <= j-1; ++k) { 
            int temp1 = solve(arr, i, k);
            int temp2 = solve(arr, k+1, j);
            int tempAns = temp1 + temp2 + arr[i-1] * arr[k] * arr[j];
            ans = min(tempAns, ans);
        }
        return ans;
    }
```

### Recursion + Memoization (Bottom Up):
```
class Solution{
public:
    int dp[101][101]; // var changed i and j and are size of arr
    int solve(int arr[], int i, int j) {
        if(i >= j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i; k < j; ++k) { 
            int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            ans = min(tempAns, ans);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, N-1);
    }
};
```

### Things to keep in mind while approaching MCM:
1. Find i, j
2. Find Base Condition
    * Think of first invalid Input: (i > j) return 0
3. Find K loop scheme
4. calculate ans from tempAns

### Basic Format:

```
    int solve(int arr[], int i, int j) {
        if(i > j) {
            return 0; // base condition can be changed
        }
        int ans = 0;
        for(int k = i; k < j; ++k) { // ++ can change, i can be i+1, j can be j-1
            // calcuate temp1 and temp2;
            int temp1 = solve(arr, i, k);
            int temp2 = solve(arr, k+1, j);
            ans += SomeOperationOn(temp1, temp2); // opr can be changed
        }
        return ans;
    }
```

### Identification of MCM problems
* dynamic programming (Choice Optimal)
* String or Array is given
* We have to take i and j 
* Loop k from i to j then call function on i = i and j = k and 2nd call on i = k+1 j = j
* and then we calcuate ans from tempAns of the each loop

### Can be solved using MCM?

### Practice problems with similar to MCM
1. [MCM](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/)
2. [Print MCM]
3. [Evaluate Expression to True](https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/)
4. [Minimum / Maximum value of an Expression]
5. [Palindromic partitioning](https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/)
6. [Scramble String](https://leetcode.com/problems/scramble-string/)
7. [Egg Droping Problem]

NOTE: Solutions are for your reference and are available in the subsequent Folder

# 5. DP on Trees

### Problem:
[Link](https://www.geeksforgeeks.org/dynamic-programming-trees-set-1/)


### Recursive Approach:
1. Base condition
2. Hypothesis (call the funstion on left and right and will never question how it gave answer)
3. Induction (using the ans from hypothesis)

### Code / Basic Format:
```
    int solve(Node* root, int& res) {
        // Base Condition
        if(root == NULL) {
            return res;
        }
        
        // hypothesis
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        // induction
        int tempAns = calculate(tempAns from l, r);
        res = someOperationOn(tempAns, res);
        
        return temp;
    }
    int Problem(Node* root) {
        int res = -1;
        solve(root, res); // please give a note here we are return ret and not solve
        return res;
    }
```

### Identification of DP on Trees problems
1. Tree is given
2. Traversing a Tree O(n)
3. for Each Node you are performing an operation worth O(n)


### Practice problems with similar to DP on Trees
1. [Diameter of a Binary Tree](https://www.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/)
2. [Diameter of a N-ary Tree]()
3. [Maximum Path Sum from any Node to other Node](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
4. [Maximum Path Sum from any leaf Node to other leaf Node](https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/) 

NOTE: Solutions are for your reference and are available in the subsequent Folder

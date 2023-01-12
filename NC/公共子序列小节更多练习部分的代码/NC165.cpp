#define MAXN  1005
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * s1和s2最长公共子序列的长度
     * @param s1 string字符串
     * @param s2 string字符串
     * @return int整型
     */
    int dp[MAXN][MAXN];
    int LCS(string A, string B) {
        // write code here
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};
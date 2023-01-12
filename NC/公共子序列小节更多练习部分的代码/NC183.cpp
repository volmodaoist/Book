#define MAXN  1005
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A int整型vector 
     * @param B int整型vector 
     * @return int整型
     */
    int dp[MAXN][MAXN];
    int longestCommonSubarry(vector<int>& A, vector<int>& B) {
        int ans = 0;
        int m =  A.size(), n = B.size();
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n ; j++){
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
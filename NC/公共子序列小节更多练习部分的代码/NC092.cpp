#define MAXN 3000
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string×Ö·û´® the string
     * @param s2 string×Ö·û´® the string
     * @return string×Ö·û´®
     */
    int dp[MAXN][MAXN];
    string LCS(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        string path;
        int i  = m, j = n;
        while(dp[i][j] >= 1){
            if(s1[i - 1] == s2[j - 1]){
                path += s1[i - 1];
                i--,j--;
            }else{
                (dp[i - 1][j] > dp[i][j - 1]) ? i--: j--;
            }
        }
        reverse(path.begin(), path.end());
        return path.empty() ? "-1" : path;
    }
};
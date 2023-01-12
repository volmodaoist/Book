#define MAXN 5005
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string×Ö·û´® the string
     * @param str2 string×Ö·û´® the string
     * @return string×Ö·û´®
     */
    int dp[MAXN][MAXN];
    string LCS(string s1, string s2) {
        // write code here
        int ans = 0, x = 0, y = 0;
        for(int i = 1; i <= s1.size(); i++){
            for(int j = 1; j <= s2.size(); j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if(dp[i][j] >= ans){
                    ans = dp[i][j], x = i, y = j;
                }
            }
        }
        // cout << ans << " " << x << " " << y << endl; 
        string path;
        int i = x, j = y;
        while(dp[i][j] >= 1){
            if(s1[i - 1] == s2[j - 1]){
                path += s1[i - 1];
                i--,j--;
            }else break;
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
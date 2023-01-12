#define MAXN 50005
class Solution {
public:
    int maxTurbulenceSize(vector<int>& x) {
        // 规定0结尾代表处于下降状态，1 结尾代表处于上升状态
        vector<vector<int>> dp(x.size(), vector<int>(2, 1));
        for(int i = 1; i < x.size(); i++){
            if(x[i - 1] < x[i]){
                dp[i][1] = dp[i - 1][0] + 1;
            }else if(x[i - 1] > x[i]){
                dp[i][0] = dp[i - 1][1] + 1; 
            }
        }
        int ans = 1;
        for(int i = 0; i < x.size(); i++){
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};
class Solution {
public:
    int dp[1005][2];
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        for(int i = 0; i < nums.size(); i++)
            dp[i][0] = dp[i][1] = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i][1] = dp[j][0] + 1;
                    dp[i][0] = max(dp[i][0], dp[j][0]);
                }else if(nums[j] > nums[i]){
                    dp[i][0] = dp[j][1] + 1;
                    dp[i][1] = max(dp[i][1], dp[j][1]);
                }
            }
            ans = max(dp[i][0], dp[i][1]);
        }
        return ans;
    }
};
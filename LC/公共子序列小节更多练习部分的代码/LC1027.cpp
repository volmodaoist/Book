class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mp;
        vector<vector<int>> dp(n , vector<int>(n , 0));
        int ans = 0;
        for(int j = 0 ; j < n ; j++){  // i, j, k
            for(int k = j + 1 ; k < n ; k++){
                int target = 2 * nums[j] - nums[k]; // 注意这里的不同,
                if(mp.count(target)){
                    dp[j][k] = dp[mp[target]][j] + 1;
                }
                ans = max(ans , dp[j][k]);
            }
            mp[nums[j]] = j; // 更新哈希表，一遍维护状态方程一遍更新哈希表能够确保 ijk 三者顺序合法
        }

        return ans + 2;
    }
};
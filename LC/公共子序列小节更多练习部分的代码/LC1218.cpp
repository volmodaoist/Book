class Solution {
public:
    int longestSubsequence(vector<int>& x, int difference) {
        int ans = 0;
        vector<int> dp(x.size(), 1); 
        map<int, int> e2i; // element to inedex 用于把元素映射为下标
        for(int i = 0; i < x.size(); i++){
            // x[i] - x[j] == difference
            if(e2i.count(x[i] - difference)){
                dp[i] = dp[e2i[x[i] - difference]] + 1;
            }
            e2i[x[i]] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
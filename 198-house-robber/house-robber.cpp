class Solution {
public:
    int take_not_take(vector<int>& nums, vector<int> &dp, int ind){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + take_not_take(nums,dp, ind -2);
        int not_take = 0 + take_not_take(nums,dp, ind-1);
        return dp[ind] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        // int start_index = 0;
        int n = nums.size();
        vector<int> dp(n+1, -1); 
        // return take_not_take(nums, dp, n-1);
        dp[0] = nums[0];
        for(int i=1; i < nums.size(); i++){
            int take = nums[i];
            if(i>1) take += dp[i-2];
            int not_take = dp[i-1];

            dp[i] = max(take, not_take);
        }

        return dp[n-1]; 
    }
};
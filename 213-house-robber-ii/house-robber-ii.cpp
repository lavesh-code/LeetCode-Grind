class Solution {
public:
int take_not_take(vector<int>& nums, vector<int> &dp, int ind){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + take_not_take(nums, dp, ind -2);
        int not_take = 0 + take_not_take(nums,dp, ind-1);
        return dp[ind] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
         if (n == 1) return nums[0]; // Special case for single house
        vector<int> temp1;
        vector<int> dp1(n, -1); 
        vector<int> temp2;
        vector<int> dp2(n,-1);

        for(int i=0; i<n; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]); 
        }

        return max(take_not_take(temp1, dp1, n-2), take_not_take(temp2, dp2, n-2));
        
    }
};
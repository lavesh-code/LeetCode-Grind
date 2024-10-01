class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;

        // Compute prefix products
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int rp = 1;
        // Compute suffix products and combine with prefix products
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rp;
            rp *= nums[i];
        }

        return result;
    }  

};
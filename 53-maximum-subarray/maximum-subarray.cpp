class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // BRUTE FORCE: O(N^3)
        // OPTIMAL : O(N) KADANE'S ALGORITHM
        // NON-EMPTY SUBARRAY REQUIRED
        int sum = 0;
        int max_sum = INT_MIN;
        int start = 0;
        int ansStart=0, ansEnd =0;  
        for(int i=0; i<nums.size(); i++){
            if(sum ==0) start = i; // starting index
            sum += nums[i];

            if(sum > max_sum){
                max_sum = sum; 
                ansStart = start;
                ansEnd = i; 

            }    
            if(sum <0) sum = 0; 
            // sum = max(0, sum); 
        }
        // non-empty subarray
        return max_sum; 
        // if asked to return possibly empty subarray 
        // return max(0,max_sum);        
    }
};
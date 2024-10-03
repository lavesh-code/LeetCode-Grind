class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        // OPTIMAL - SINGLE PASS
        unordered_map<int,int> map; // number : index
        for(int i=0; i < n; i++){
            // number that would be required to sum to target
            int complement = target - nums[i];
            // check if complement exist in hashmap
            if(map.count(complement)){
                // if exist return {index of complement, curr_index of iteration}
                return {map[complement] +1, i +1};
            }
            // else store the current number and its index in map
            map[nums[i]] = i; 
        }
        // if no pair found then return {-1,-1}
        return {-1,-1}; 
    }
};
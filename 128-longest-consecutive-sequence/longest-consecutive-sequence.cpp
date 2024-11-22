class Solution {
public:
    int longestConsecutive(vector<int>& nums) { // TC: O(N + 2N), SC: O(N)
        int n = nums.size();
        int longest = 1;
        if(n == 0) return n;

        unordered_set<int> st; // find takes O(1)
        // first iteration to store eveything in theset
        for(int i=0; i < n; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            // if it is the firt element : previous not in set
            // if x - 1 present in set (mid of sequence), then me wove to next it
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x + 1;
                    cnt += 1;
                }
                longest=max(longest,cnt);

            }
        }
        return longest;
    }
};
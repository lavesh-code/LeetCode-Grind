class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> hash(256, -1);
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;

        while (right < n) {
            // if char exist in map, so move left one ahead of s[right] if left < s[right]...
            // else keep it there itself, means s[right]
            if (hash[s[right]] != -1){
                if(hash[s[right]] >= left){
                    left = hash[s[right]] + 1;
                }
                // left = max(hash[s[right]] + 1, left);
            }

            hash[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
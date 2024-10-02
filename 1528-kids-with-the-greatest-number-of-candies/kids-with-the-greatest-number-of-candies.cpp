class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = -1;
        int n = candies.size(); 
        for(int i = 0; i < n; i++){
            max_candies = max(max_candies, candies[i]);
        }

        vector<bool> result;
        for(int i=0; i <n; i++){
           if(candies[i] + extraCandies - max_candies >=0)  result.push_back(true);
           else result.push_back(false);
        }

        return result; 
        
    }
};
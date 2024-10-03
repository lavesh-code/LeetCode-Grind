class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i=0;i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]); 
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);            
            }
        }

        return ans; 
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        return merge(intervals);
        
    }
};
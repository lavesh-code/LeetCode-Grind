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
        // NAIVE APPROACH - PUSH THE NEW INTERVAL AND THEN CALL MERGE INTERVALS
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end());
        // return merge(intervals);

        // OPTIMAL APPROACH:
        int n = intervals.size();
        int i =0;
        vector<vector<int>> result;
        // Step 1: Add all intervals jo newInterval ke pehle khatam ho jaate hain
        // (Unka ending point, newInterval ke start point se chota hai)
        while( i< n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }
        // Step 2: Merge karte hain sabhi intervals ko jo newInterval 
        // se overlap karte hain
        // (Unka starting point, newInterval ke ending point se chota hai)
        while(i < n && intervals[i][0] <= newInterval[1]){ // equals is important
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

        return result; 

        
    }
};
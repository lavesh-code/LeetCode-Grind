class Solution {
private:
    static bool comp(vector<int> &val1, vector<int> &val2){
        return val1[1] < val2[1]; 
    }    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp); 
        int n = intervals.size();
        int count = 1; 
        int lastendtime = intervals[0][1];

        for(int i=0; i <n; i++){
            if(intervals[i][0] >= lastendtime){
                count++;
                lastendtime = intervals[i][1];
            }
        }

        return n - count; 
        
    }
};
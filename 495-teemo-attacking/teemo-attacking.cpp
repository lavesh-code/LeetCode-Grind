class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int lv=timeSeries.size();
        long long cnt=1ll*duration*lv;//     assume that there is no duplication
        for(int i=0;i<lv-1;++i)
            if(timeSeries[i+1]-timeSeries[i]<duration) cnt-=duration-(timeSeries[i+1]-timeSeries[i]);//     remove the duplication
        return (int)cnt;
    }
};
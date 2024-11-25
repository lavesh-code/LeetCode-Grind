class Solution {
private:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n,0);
        vector<int> ans;
        
        for(auto it : adj){
            for(auto nbr : it){
                indegree[nbr]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i <n; i++){
            if(indegree[i] ==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] ==0){
                    q.push(nbr);
                }
            }
            
        }
        
        return ans; 
    }

public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> topo = topologicalSort(adj);

        if(topo.size()==V) return true;
        return false; 
    }
};
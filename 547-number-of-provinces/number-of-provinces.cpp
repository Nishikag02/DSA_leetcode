class Solution {
public:

    void dfs(int src,vector<vector<int>>&graph,vector<bool>&vis){
        vis[src]=true;
        vector<int>neigh=graph[src];
        for(int v : neigh){
            if(!vis[v]){
                dfs(v,graph,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int V=isConnected.size();
        vector<bool>vis(V,false);
        vector<vector<int>>graph(V);
        int count=0;

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(i!=j && isConnected[i][j]==1){
                    graph[i].push_back(j);
                }
            }
        }

        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,graph,vis);
            }
        }

        return count;
        
    }
};
class Solution {
public:

    bool dfs(int src,int dest,vector<vector<int>>&graph,vector<bool>&vis,int V){
        if(src==dest){
            return true;
        }
        vis[src]=true;

        vector<int>neigh=graph[src];
        for(int v:neigh){
            if(!vis[v]){
                if(dfs(v,dest,graph,vis,V)){
                    return true;
                }
            }
        }
        
        return false;
    }

    bool validPath(int V, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(V,false);
        vector<vector<int>>graph(V);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return dfs(source,destination,graph,vis,V);
        
    }
};
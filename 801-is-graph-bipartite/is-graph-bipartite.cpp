class Solution {
public:

    bool helper(int src,vector<bool>&vis,vector<vector<int>>& graph,vector<int>&color){
        queue<int>q;
        q.push(src);
        vis[src]=true;
        color[src]=0;

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vector<int> neigh=graph[curr];
            for(int v:neigh){
                if(!vis[v]){
                    vis[v]=true;
                    color[v]=!color[curr];
                    q.push(v);
                }
                else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<bool>vis(V,false);
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(!helper(i,vis,graph,color)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
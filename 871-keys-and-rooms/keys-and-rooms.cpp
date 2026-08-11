class Solution {
public:

    void bfs(int src,vector<vector<int>>&rooms,vector<bool>&vis){
        queue<int>q;
        q.push(src);
        vis[src]=true;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            vector<int>keys=rooms[u];
            for(int v:keys){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V=rooms.size();
        vector<bool>vis(V,false);
        bfs(0,rooms,vis);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};
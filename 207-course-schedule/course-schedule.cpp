class Solution {
public:

    bool helper(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>&graph,int V){

        vis[src]=true;
        recPath[src]=true;

        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];

            if(src==u){
                if(!vis[v]){
                    if(helper(v,vis,recPath,graph,V)){
                        return true;
                    }
                }
                else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& graph) {

        int V=numCourses;
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i,vis,recPath,graph,V)){
                    return false;
                }
            }
        }

        return true;
        
    }
};
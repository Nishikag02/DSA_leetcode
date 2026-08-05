class Solution {
public:

    bool isCycle(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>& graph){

        vis[src]=true;
        recPath[src]=true;

        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];

            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,vis,recPath,graph)){
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

    void topologicalSort(int src,vector<bool>&vis,vector<vector<int>>& graph,stack<int>&s){

        vis[src]=true;

        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];

            if(u==src){
                if(!vis[v]){
                    topologicalSort(v,vis,graph,s);
                }
            }
        }
        s.push(src);

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {

        int V=numCourses;
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(i,vis,recPath,graph)){
                    return {};
                }
            }
        }

        fill(vis.begin(),vis.end(),false);
        stack<int> s;

        for(int i=0;i<V;i++){
            if(!vis[i]){
                topologicalSort(i,vis,graph,s);
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;


        
    }
};
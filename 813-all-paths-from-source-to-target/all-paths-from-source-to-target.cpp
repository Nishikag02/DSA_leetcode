class Solution {
public:

    void helper(int src, int dest,
            vector<vector<int>>& graph,
            vector<bool>& vis,
            vector<int>& path,
            vector<vector<int>>& ans){

                vis[src]=true;
                path.push_back(src);

                if(src==dest){
                    ans.push_back(path);
                }
                else{
                    for(int v : graph[src]){
                        if(!vis[v]){
                            helper(v, dest, graph, vis, path, ans);
                        }
                    }
                }
                path.pop_back();
                vis[src] = false; 
            }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> vis(graph.size(), false);

        helper(0, graph.size()-1, graph, vis, path, ans);
            return ans;
        }
};
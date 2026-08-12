class Solution {
public:

    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }

        if(vis[i][j]){
            return 0;
        }

        vis[i][j]=true;

        int ans=0;

        ans+=dfs(i-1,j,grid,vis);
        ans+=dfs(i+1,j,grid,vis);
        ans+=dfs(i,j-1,grid,vis);
        ans+=dfs(i,j+1,grid,vis);

        return ans+1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans=max(ans,dfs(i,j,grid,vis));

                }
            }
        }

        return ans;
        
    }
};
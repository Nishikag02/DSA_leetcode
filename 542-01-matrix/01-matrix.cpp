class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;

            q.pop();

            ans[i][j]=time;

            if(i-1>=0 && !vis[i-1][j]){
                vis[i-1][j]=true;
                q.push({{i-1,j},time+1});
            }
            if(i+1<n && !vis[i+1][j]){
                vis[i+1][j]=true;
                q.push({{i+1,j},time+1});
            }
            if(j-1>=0 && !vis[i][j-1]){
                vis[i][j-1]=true;
                q.push({{i,j-1},time+1});
            }
            if(j+1<m && !vis[i][j+1]){
                vis[i][j+1]=true;
                q.push({{i,j+1},time+1});
            }

        }

        return ans;
        
    }
};
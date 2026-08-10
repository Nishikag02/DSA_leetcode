class Solution {
public:

    void dfs(int row,int col,int n,int m,vector<vector<int>>& image,vector<vector<bool>>&vis,int newCol,int oldCol){
        vis[row][col]=true;
        image[row][col]=newCol;

        //up
        if(row-1>=0 && !vis[row-1][col] && image[row-1][col]==oldCol){
            dfs(row-1,col,n,m,image,vis,newCol,oldCol);
        }

         //down
        if(row+1<n && !vis[row+1][col] && image[row+1][col]==oldCol){
            dfs(row+1,col,n,m,image,vis,newCol,oldCol);
        }

         //left
        if(col-1>=0 && !vis[row][col-1] && image[row][col-1]==oldCol){
            dfs(row,col-1,n,m,image,vis,newCol,oldCol);
        }

         //up
        if(col+1<m && !vis[row][col+1] && image[row][col+1]==oldCol){
            dfs(row,col+1,n,m,image,vis,newCol,oldCol);
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int Newcolor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dfs(sr,sc,n,m,image,vis,Newcolor,image[sr][sc]);

        return image;
        
    }
};
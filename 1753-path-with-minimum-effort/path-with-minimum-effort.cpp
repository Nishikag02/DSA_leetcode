class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();
         
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int effort=pq.top().first;

            pq.pop();

            //up
            if(r-1>=0){
                int nr=r-1;
                int nc=c;
                int wt=abs(heights[nr][nc]-heights[r][c]);
                int newEffort=max(effort,wt);
                if(dist[nr][nc]>newEffort){
                    dist[nr][nc]=newEffort;
                    pq.push({newEffort,{nr,nc}});
                }
            }

            //down
             if(r+1<n){
                int nr=r+1;
                int nc=c;
                int wt=abs(heights[nr][nc]-heights[r][c]);
                int newEffort=max(effort,wt);
                if(dist[nr][nc]>newEffort){
                    dist[nr][nc]=newEffort;
                    pq.push({newEffort,{nr,nc}});
                }
            }

            //left
             if(c-1>=0){
                int nr=r;
                int nc=c-1;
                int wt=abs(heights[nr][nc]-heights[r][c]);
                int newEffort=max(effort,wt);
                if(dist[nr][nc]>newEffort){
                    dist[nr][nc]=newEffort;
                    pq.push({newEffort,{nr,nc}});
                }
            }

            //right
             if(c+1<m){
                int nr=r;
                int nc=c+1;
                int wt=abs(heights[nr][nc]-heights[r][c]);
                int newEffort=max(effort,wt);
                if(dist[nr][nc]>newEffort){
                    dist[nr][nc]=newEffort;
                    pq.push({newEffort,{nr,nc}});
                }
            }

            
        }

        return dist[n-1][m-1];
        
    }
};
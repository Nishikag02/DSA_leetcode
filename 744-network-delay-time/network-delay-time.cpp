class Solution {
public:

    void dijkstra(vector<vector<int>>& times, int n, int k , vector<int>&dist){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push(make_pair(0,k));

        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(int i=0;i<times.size();i++){
                if(times[i][0]==u){
                    int v=times[i][1];
                    int wt=times[i][2];

                    if(dist[v]>dist[u]+wt){
                        dist[v]=dist[u]+wt;
                        pq.push({dist[v],v});
                    }
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);

        dijkstra(times,n,k,dist);

        int ans=0;

        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }

        return ans==INT_MAX ? -1 : ans;
        
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int V=points.size();
        vector<bool>mst(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int src=0;
        pq.push(make_pair(0,src));
        int minCost=0;

        while(!pq.empty()){
            auto curr=pq.top();
            int u=curr.second;
            int cost=curr.first;
            pq.pop();
            
            if(!mst[u]){
            mst[u]=true;
            minCost+=cost;
            
            for(int v=0;v<V;v++){
                if(u!=v){
                    int wt=abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                    pq.push(make_pair(wt,v));
                }
            }
            }
        }

        return minCost;



        
    }
};
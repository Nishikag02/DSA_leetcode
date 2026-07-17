class Solution {
public:

    class Point{
    public:
        int idx;
        int distSq;

        Point(int idx,int distSq){
            this->idx=idx;
            this->distSq=distSq;
        }

        bool operator < (const Point &obj)const{
            return this->distSq > obj.distSq;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<vector<int>>ans;
        int n=points.size();

        vector<Point>p;

        for(int i=0;i<n;i++){
            int Sq= points[i][0]*points[i][0] + points[i][1]*points[i][1];
            Point p1(i,Sq);
            p.push_back(p1);
        }

        priority_queue<Point>pq(p.begin(),p.end());

        for(int i=0;i<k;i++){
            Point P=pq.top();
            ans.push_back(points[P.idx]);
            pq.pop();
        }

        return ans;


        
    }
};
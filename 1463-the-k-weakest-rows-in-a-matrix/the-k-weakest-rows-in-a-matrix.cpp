class Solution {
public:

    class Row{

        public:
        int count;
        int idx;

        Row(int count,int idx){
            this->count=count;
            this->idx=idx;
        }

        bool operator <(const Row &obj)const{
            if(this->count==obj.count){
                return this->idx > obj.idx;
            }
            return this->count > obj.count;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<Row> r;
        vector<int>ans;

        for(int i=0;i<mat.size();i++){
             int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            Row r1(count,i);
            r.push_back(r1);
        }

        priority_queue<Row> pq(r.begin(),r.end());

        for(int i=0;i<k;i++){
            Row R=pq.top();
            ans.push_back(R.idx);
            pq.pop();
        }

        return ans;
        
    }
};
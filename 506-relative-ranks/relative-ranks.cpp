class Solution {
public:

    class Athlete{
    public:
        int idx;
        int val;
        int rank;

        Athlete(int idx,int val,int rank){
            this->idx=idx;
            this->val=val;
            this->rank=rank;
        }

        bool operator < (const Athlete & obj)const{
            return this->val<obj.val;
        }
    };

    vector<string> findRelativeRanks(vector<int>& score) {

        vector<Athlete>a;
        int n=score.size();
        vector<string>ans(n);

        for(int i=0;i<score.size();i++){
            a.push_back(Athlete(i,score[i],0));
        }

        priority_queue<Athlete>pq(a.begin(),a.end());

        int rank=1;

        while(!pq.empty()){
            Athlete a1=pq.top();
            pq.pop();

            a[a1.idx].rank=rank;
            rank++;
        }

        for(int i=0;i<n;i++){
            if(a[i].rank==1){
                ans[i]="Gold Medal";
            }
            else if (a[i].rank == 2)
                ans[i] = "Silver Medal";
            else if (a[i].rank == 3)
                ans[i] = "Bronze Medal";
            else
                ans[i] = to_string(a[i].rank);
        }

        return ans;

       
        
    }
};
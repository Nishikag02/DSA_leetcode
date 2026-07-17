class Solution {
public:
    class Num{
    public:

        int idx;
        int val;

        Num(int idx,int val){
            this->idx=idx;
            this->val=val;
        }

        bool operator <(const Num &obj)const{
            return this->val<obj.val;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        int n=nums.size();
        priority_queue<Num> pq;

        for(int i=0;i<k;i++){
            Num n1(i,nums[i]);
            pq.push(n1);
        }
        ans.push_back(pq.top().val);

        for(int i=k;i<n;i++){
            while(!pq.empty() && pq.top().idx<=i-k){
                pq.pop();
            }
            pq.push(Num(i,nums[i]));
            ans.push_back(pq.top().val);
        }

        return ans;
        
    }
};
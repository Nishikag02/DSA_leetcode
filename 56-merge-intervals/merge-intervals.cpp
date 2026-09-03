class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n=intervals.size();
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());

        int st=intervals[0][0];
        int end=intervals[0][1];

        for(int j=1;j<n;j++){
            int currst=intervals[j][0];
            int currend=intervals[j][1];

            if(currst<=end){
                end=max(end,currend);
            }
            else{
                ans.push_back({st,end});
                st=currst;
                end=currend;
            }
        }

        ans.push_back({st,end});

        return ans;
        
    }
};
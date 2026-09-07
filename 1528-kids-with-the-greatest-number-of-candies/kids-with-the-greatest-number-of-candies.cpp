class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        vector<bool>ans; 

        int curr_max=INT_MIN;

        for(int curr_candy:candies){
            curr_max=max(curr_max,curr_candy);
        }

        for(int i : candies){
            int total_candies=i+extraCandies;
            if(total_candies>=curr_max){
                ans.push_back(true);

            }
            else{
                ans.push_back(false);
            }
        }

        return ans;

        
    }
};
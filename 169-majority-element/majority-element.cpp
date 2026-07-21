class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++){
            
            if(m[nums[i]]){
                m[nums[i]]++;
            }
            else{
                m[nums[i]]=1;
            }
        }

        for(auto pair:m){
            if(pair.second>nums.size()/2){
                return pair.first;
            }
        }

        return -1;

        
    }
};
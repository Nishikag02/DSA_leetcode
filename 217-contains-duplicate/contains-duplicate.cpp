class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;

        for(int curr:nums){
            if(s.find(curr)!=s.end()){
                return true;
            }
            s.insert(curr);
        }

        return false;
    }
};
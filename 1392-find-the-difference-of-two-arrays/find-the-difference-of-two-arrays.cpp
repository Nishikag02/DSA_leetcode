class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int>s1,s2;
        vector<vector<int>>ans;

        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }

        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
            if(s1.find(nums2[i])!=s1.end()){
                s1.erase(nums2[i]);
            }
        }
        
        for(int i=0;i<nums1.size();i++){
            if(s2.find(nums1[i])!=s2.end()){
                s2.erase(nums1[i]);
            }
        }

        vector<int> v1(s1.begin(),s1.end());
        vector<int> v2(s2.begin(),s2.end());


        ans.push_back(v1);
        ans.push_back(v2);

        return ans;



        
    }
};
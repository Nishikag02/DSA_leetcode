class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        int n=candyType.size();
        unordered_set<int>s;

        for(int i=0;i<n;i++){
            s.insert(candyType[i]);
        }

        int distinct=s.size();

        return distinct<n/2 ? distinct : n/2;
        
    }
};
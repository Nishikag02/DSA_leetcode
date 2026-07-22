class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        int n=paths.size();
        unordered_set<string> s;

        for(int i=0;i<n;i++){
            s.insert(paths[i][0]);
        }

        for(int i=0;i<n;i++){
            if(s.find(paths[i][1])==s.end()){
                return paths[i][1];
            }
        }

        return "";




        
    }
};
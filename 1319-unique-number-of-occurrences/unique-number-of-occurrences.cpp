class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            if(m.count(arr[i])){
                m[arr[i]]++;
            }
            else{
                m[arr[i]]=1;
            }
        }

        unordered_set<int>s;

        for(auto el:m){
            int freq=el.second;
            if(s.find(freq)!=s.end()){
                return false;
            }
            s.insert(freq);
        }
        return true;
    }
};
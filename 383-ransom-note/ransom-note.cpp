class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<int,int>m;

        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++;
        }

        for(int i=0;i<ransomNote.size();i++){
            if(m.count(ransomNote[i])){
                m[ransomNote[i]]--;

                if(m[ransomNote[i]]==0){
                    m.erase(ransomNote[i]);
                }
            }
            else{
                return false;
            }
        }

        return true;
        
    }
};
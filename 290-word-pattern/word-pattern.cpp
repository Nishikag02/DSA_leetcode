class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char,string>m1;
        unordered_map<string,char>m2;
        int j=0;

        for(int i=0;i<pattern.size();i++){

            if(j>=s.size()){
                return false;
            }
            char ch=pattern[i];

            string word="";
            
            while(j<s.size() && s[j]!=' '){
                word=word+s[j];
                j++;
            }
            j++;

            if(m1.count(ch)!=0 && m1[ch]!=word){
                return false;
            }

            if(m2.count(word)!=0 && m2[word]!=ch){
                return false;
            }

            m1[ch]=word;
            m2[word]=ch;
        }

        if(j<s.size()){
            return false;
        }

        return true;
        
    }
};
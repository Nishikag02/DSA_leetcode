class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        unordered_map<char,int>m;
        int sum=0;
        

        for(char ch:chars){
            m[ch]++;
        }

        for(int i=0;i<words.size();i++){
            unordered_map<char,int>temp=m;
            bool possible=true;
            string word=words[i];

            for(char ch:word){
                if(temp.count(ch)){
                    temp[ch]--;
                    if(temp[ch]==0){
                        temp.erase(ch);
                    }
                }
                else{
                    possible=false;
                    break;
                }
            }

            if(possible){
                sum+=word.length();
            }
        }

        return sum;
        
    }
};
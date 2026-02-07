class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        int word=0;
        for(int i=0;i<text.size();i++){
            bool exist=0;
            vector<int>list(127,0);
            while(text[i]!=' ' && i<text.size()){
                list[text[i]]++;
                i++;
            }
            for(int j=0;j<brokenLetters.size();j++){
                if(list[brokenLetters[j]]>0){
                    exist=1;
                    break;
                }
            }
            if(!exist) word++;
        }
        return word;
    }
};
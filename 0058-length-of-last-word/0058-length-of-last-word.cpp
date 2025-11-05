class Solution {
public:
    int lengthOfLastWord(string s) {
        int size=0;
        bool ready=0;
        for(int i=s.size()-1;i>-1;i--){
            if((s[i]==' ' )&& (ready==0) ){
                continue;
            }
            ready=1;
            if(s[i]!=' '){
                size++;
                continue;
            }
            break;
        }
        return size;
        
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()==1){
            return 0;
        }
        for(int i=0;i<haystack.size();i++){
            string part=haystack.substr(i,needle.size());
            if(part==needle){
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        string ans="";
        int size=1;
        while(size<=strs[0].size()){
            for(int i=0;i<strs.size()-1;i++){
                if(strs[i].substr(0,size)!=strs[i+1].substr(0,size))return ans;
            }
            ans=strs[0].substr(0,size);
            size++;
        }
        return ans;
        

    }
};
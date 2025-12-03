class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> un(128,0);
        for(int i=0;i<s.size();i++){
            un[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(un[s[i]]==1)return i;
        }
        return -1;

        
    }
};
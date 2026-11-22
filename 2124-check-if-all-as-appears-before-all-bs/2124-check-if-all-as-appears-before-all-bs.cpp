class Solution {
public:
    bool checkString(string s) {
        bool a=true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')a=false;
            if(s[i]=='a'&&!a)return false;
        }
        return true;
    }
};
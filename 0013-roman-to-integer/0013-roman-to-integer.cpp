class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        for (int i=0;i<s.size();i++){
            if(i<s.size()-1 && s[i]=='I'&& s[i+1]=='V' ){
                res=res+4;
                i++;
                continue;
            }
            if(i<s.size()-1 && s[i]=='I'&& s[i+1]=='X' ){
                res=res+9;
                i++;
                continue;
            }
            if(i<s.size()-1 && s[i]=='X'&& s[i+1]=='L' ){
                res=res+40;
                i++;
                continue;
            }
            if(i<s.size()-1 && s[i]=='X'&& s[i+1]=='C' ){
                res=res+90;
                i++;
                continue;
            }
            if(i<s.size()-1 && s[i]=='C'&& s[i+1]=='D' ){
                res=res+400;
                i++;
                continue;
            }
            if(i<s.size()-1 && s[i]=='C'&& s[i+1]=='M' ){
                res=res+900;
                i++;
                continue;
            }
            (s[i]=='I')? res=res+1:res;
            (s[i]=='V')? res=res+5:res;
            (s[i]=='X')? res=res+10:res;
            (s[i]=='L')? res=res+50:res;
            (s[i]=='C')? res=res+100:res;
            (s[i]=='D')? res=res+500:res;
            (s[i]=='M')? res=res+1000:res;
        }
        return res;

    }
};
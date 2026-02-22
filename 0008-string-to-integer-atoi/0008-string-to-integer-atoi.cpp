class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;

        while(i<s.size() && s[i]==' ')i++;

        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-')sign=-1;
            i++;
        }
        long ans=0;
        while(i<s.size() && isdigit(s[i])){
            int dig=s[i]-'0';
            if((((ans*10)+dig)*sign) >INT_MAX)return INT_MAX;
            if((((ans*10)+dig)*sign) <INT_MIN)return INT_MIN;
            ans=(ans*10)+dig;
            i++;          
        }
        return sign*ans;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string ans,temp;
        int flag=0,m=0;
        for(int i=0;i<s.size()-1;i++){
            for(int j=i+1;j<s.size();j++){
                int start=i,end=j;
                while(start<end){
                    if(s[start]!=s[end]){
                        flag=1;
                        break;
                    }
                    start++;
                    end--;
                }
                if(flag==0){
                    temp=s.substr(i,j-i+1);
                    if(temp.size()>m){
                        m=temp.size();
                        ans=s.substr(i,j-i+1);
                    } 
                }
                else{
                    flag=0;
                }
            }
        }
        if(ans.size()==0) ans=s[0];
    
        return ans;
    }
};
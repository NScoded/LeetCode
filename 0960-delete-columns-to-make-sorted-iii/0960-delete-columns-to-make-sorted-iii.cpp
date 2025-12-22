class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int>dp(strs[0].size(),1);
        for(int j=strs[0].size()-2;j>=0;j--){
            for(int i=j+1;i<strs[0].size();i++){
                bool valid=true;
                for(int row=0;row<strs.size();row++){
                    if(strs[row][j]>strs[row][i]){
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        sort(dp.begin(),dp.end());
        return strs[0].size()-dp[dp.size()-1];
        
    }
};
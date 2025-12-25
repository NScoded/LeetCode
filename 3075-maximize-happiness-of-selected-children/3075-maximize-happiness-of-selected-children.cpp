class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long dec=0;
        long ans=0;
        for(int i=happiness.size()-1;i>=0 && happiness.size()-i<=k;i--){
            if(happiness[i]-dec<=0)break;
            ans=ans+happiness[i]-dec;
            dec++;
        }
        return ans;
    }
};
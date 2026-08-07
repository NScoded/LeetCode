class Solution {
public:

    
    int countPrimes(int n) {
        if(n<3)return 0;
        
        int ans=0;
        vector<bool>num(n,true);
        for(int i=3;i<n;i=i+2){
            if(num[i]){
                ans++;
                int j=1;
                while(j*i<n){
                    num[j*i]=false;
                    j++;
                }
            }
        }
        return ans+1;

        

        
    }
};
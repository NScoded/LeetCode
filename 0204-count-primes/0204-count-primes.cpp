class Solution {
public:

    
    int countPrimes(int n) {
        int ans=0;
        vector<bool>num(n,true);
        for(int i=2;i<n;i++){
            if(num[i]){
                ans++;
                int j=1;
                while(j*i<n){
                    num[j*i]=false;
                    j++;
                }
            }
        }
        return ans;

        

        
    }
};
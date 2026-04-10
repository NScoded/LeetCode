class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int m=INT_MAX;
        bool hit=true;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    for(int k=j+1;k<nums.size();k++){
                        if(nums[j]==nums[k]){
                            m=min(m,abs(i-j)+abs(j-k)+abs(k-i));
                            hit=false;
                        }
                    }
                }
            }
        }
        if(hit) return -1;
        return m;
    }
};
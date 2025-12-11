class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        int jump=0,m=0,index=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i+nums[i]>=nums.size()-1) return true;
            int m=INT_MIN,index=i;
            for(int j=i+1;j<=i+nums[i];j++){
                if(m<j+nums[j]){
                    m=j+nums[j];
                    index=j;
                }
            }
            if(m<1)return false;
            i=index-1;
        }
        return false;
    }
};
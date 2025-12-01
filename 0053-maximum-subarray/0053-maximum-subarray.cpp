class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,ms=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cs=max(cs+nums[i],nums[i]);
            ms=max(ms,cs);
        }
        return ms;
    }
};
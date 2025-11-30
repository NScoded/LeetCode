class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
                i--;k--;
                continue;
            }
        }
        return k;
    }
};
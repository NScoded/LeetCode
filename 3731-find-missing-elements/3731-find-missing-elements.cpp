class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]-1){
                int num=nums[i]+1;
                while(nums[i+1]!=num){
                    ans.push_back(num);
                    num++;
                }
            }
        }
        return ans;
    }
};
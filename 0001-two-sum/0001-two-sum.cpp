class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            int req=target-nums[i];
            if(map.count(req)) return {map[req],i};
            map[nums[i]]=i;
        }
        return {};
    }
};

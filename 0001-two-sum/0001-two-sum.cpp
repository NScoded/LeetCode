class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // value → index
        
        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            
            if(mp.count(need)) {         // if complement exists
                return {mp[need], i};
            }
            
            mp[nums[i]] = i;             // store current value
        }
        
        return {};
    }
};

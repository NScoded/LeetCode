class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0;
        int window=0;
        int left=0;
        unordered_map<int,int>freq;
        for(int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            window++;

            while(freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
                window--;
            }
            
            ans=max(ans,window);
        }
        return ans;
        
    }
};
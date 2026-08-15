class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        int j=0;
        if(nums.size()<2){
            return (nums[0])? 1:0;
        }
        size_t sum=nums[0];

        for(int i=1;i<nums.size();i++){
            sum=sum+nums[i];
            nums[i]^=nums[i-1];
            if(nums[i])ans=max(ans,i-j+1);
        }
        int i=nums.size()-1;
        if(!sum)return 0;
        while(!nums[i] && j<i){
            nums[i]^=nums[j];
            j++;
            ans=max(ans,i - j +1);
        }



        // unordered_map<int,int>freq;
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        //     while(freq[nums[i]]%2==0 && j<i){
        //         freq[nums[j]]--;
        //         j++;
        //     }
        //     ans=max(ans,i-j+1);
        // }
        return ans;
    }
};
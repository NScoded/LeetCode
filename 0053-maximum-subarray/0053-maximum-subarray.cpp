class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Kadan's By Own 
       int currentSum=0,maxSum=INT_MIN;
       for(int val:nums){
        currentSum=max(currentSum+val,val);
        maxSum=max(maxSum,currentSum);
       }
        return maxSum;
    }
};
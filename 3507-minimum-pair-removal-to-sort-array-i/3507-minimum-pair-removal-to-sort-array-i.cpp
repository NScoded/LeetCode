class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        
        while (true) {
            bool sorted = true;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }
            
            if (sorted) break;
            
            // find pair with minimum sum
            int minSum = INT_MAX;
            int index = 0;
            
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }
            
            // merge that pair
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);
            
            operations++;
        }
        
        return operations;
    }
};
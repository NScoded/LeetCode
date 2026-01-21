class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums) {
            // If num == 2, no valid ans exists because 2 is even
            if (num == 2) {
                ans.push_back(-1);
                continue;
            }

            // Find the first 0 bit in num starting from bit position 1
            for (int bitPos = 1; bitPos < 32; ++bitPos) {
                // If the bit at bitPos is 0
                if (((num >> bitPos) & 1) == 0) {
                    // Flip the (bitPos - 1) bit to get the minimum a
                    ans.push_back(num ^ (1 << (bitPos - 1)));
                    break;
                }
            }
        }
        return ans;
    }
};

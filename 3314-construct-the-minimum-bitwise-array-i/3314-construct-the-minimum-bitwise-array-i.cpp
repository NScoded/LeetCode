class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            if (p == 2) {
                ans.push_back(-1);
            } else {
                int low = (p + 1) & -(p + 1); // lowest set bit of (p+1)
                int x = p - (low / 2);
                ans.push_back(x);
            }
        }
        return ans;
    }
};

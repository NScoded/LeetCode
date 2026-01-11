class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (auto &row : matrix) {
            for (int i = 0; i < n; i++) {
                if (row[i] == '1')
                    height[i]++;
                else
                    height[i] = 0;
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int maxA = 0;
        h.push_back(0);

        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        h.pop_back();
        return maxA;
    }
};

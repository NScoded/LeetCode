class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> p(n+1, vector<int>(m+1, 0));

        // Prefix sum
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                p[i][j] = mat[i-1][j-1] + p[i-1][j] + p[i][j-1] - p[i-1][j-1];

        auto possible = [&](int k) {
            for(int i = 0; i + k <= n; i++)
                for(int j = 0; j + k <= m; j++) {
                    int sum = p[i+k][j+k] - p[i][j+k] - p[i+k][j] + p[i][j];
                    if(sum <= threshold) return true;
                }
            return false;
        };

        int low = 0, high = min(n, m), ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(possible(mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};

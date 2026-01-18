class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // Prefix sums
        vector<vector<int>> row(m+1, vector<int>(n+1, 0));
        vector<vector<int>> col(m+1, vector<int>(n+1, 0));
        vector<vector<int>> diag1(m+1, vector<int>(n+1, 0));
        vector<vector<int>> diag2(m+1, vector<int>(n+2, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i+1][j+1] = row[i+1][j] + grid[i][j];
                col[i+1][j+1] = col[i][j+1] + grid[i][j];
                diag1[i+1][j+1] = diag1[i][j] + grid[i][j];
                diag2[i+1][j] = diag2[i][j+1] + grid[i][j];
            }
        }

        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    int sum = row[i+1][j+k] - row[i+1][j];
                    bool ok = true;

                    // check rows
                    for (int r = i; r < i+k; r++)
                        if (row[r+1][j+k] - row[r+1][j] != sum) ok = false;

                    // check cols
                    for (int c = j; c < j+k; c++)
                        if (col[i+k][c+1] - col[i][c+1] != sum) ok = false;

                    // check diagonals
                    if (diag1[i+k][j+k] - diag1[i][j] != sum) ok = false;
                    if (diag2[i+k][j] - diag2[i][j+k] != sum) ok = false;

                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};

class Solution {
public:
    /*This code takes more time than it needs to.
    Because to fill each house in the first row of the dp table, two conditions must be checked,
    and to fill each house in the first column, it must check three conditions each time.
    Whereas, if we put a separate for loop to fill the first row, one to fill the first column,
    and another to fill the other houses, the execution time would be better.*/
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int** dp = new int* [n];
        for (int i = 0; i < n; i++)
            dp[i] = new int[m] {0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                else if (i - 1 < 0 && j - 1 >= 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (i - 1 >= 0 && j - 1 < 0)
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                else dp[i][j] = grid[i][j];

            }
        }
        return dp[n - 1][m - 1];
    }
};
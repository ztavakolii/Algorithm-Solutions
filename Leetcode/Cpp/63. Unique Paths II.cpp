class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int** dp = new int* [m];
        for (int i = 0; i < m; i++)
            dp[i] = new int[n] {0};
        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        else dp[0][0] = 0;
        for (int i = 1; i < m; i++)
            if (obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
            else dp[i][0] = 0;
        for (int i = 1; i < n; i++)
            if (obstacleGrid[0][i] == 0)
                dp[0][i] = dp[0][i - 1];
            else dp[0][i] = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }
};
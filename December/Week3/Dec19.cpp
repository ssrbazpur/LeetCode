//TC: O(N*M*M) | SC:O(N*M*M)
class Solution
{
private:
    int n;
    int m;

    int dfs(vector<vector<int>> &grid, int n, int m, int r, int c1, int c2, vector<vector<vector<int>>> &dp)
    {

        //Base Case:
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m || r >= n || r < 0)
        {
            return 0;
        }

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        //Recursive Case
        int maxsum = 0;
        //3 choice for c1 and 3 choice for c2. Total Combinations 3*3=9
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newc1 = c1 + i;
                int newc2 = c2 + j;
                maxsum = max(maxsum, dfs(grid, n, m, r + 1, newc1, newc2, dp));
            }
        }

        int currCherry = 0;
        if (c1 == c2)
        {
            currCherry = grid[r][c1];
        }
        else
        {
            currCherry = grid[r][c1] + grid[r][c2];
        }

        dp[r][c1][c2] = currCherry + maxsum;
        return dp[r][c1][c2];
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // int dp[n][m][m]={-1};
        return dfs(grid, n, m, 0, 0, m - 1, dp);
    }
};
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        if (grid[0][0] != 0)
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int ans = 0;

        while (!q.empty())
        {

            int size = q.size();
            cout << size;
            while (size-- > 0)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if (i == grid.size() - 1 && j == grid[0].size() - 1 && grid[i][j] == 0)
                {
                    return ans + 1;
                }

                if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] != 0)
                {
                    continue;
                }
                grid[i][j] = 1;

                q.push({i - 1, j});
                q.push({i + 1, j});
                q.push({i, j - 1});
                q.push({i, j + 1});
                q.push({i - 1, j - 1});
                q.push({i + 1, j + 1});
                q.push({i + 1, j - 1});
                q.push({i - 1, j + 1});
            }
            ans++;
        }

        return -1;
    }
};
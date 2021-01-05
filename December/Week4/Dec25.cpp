class Solution
{
public:
    //Time:O(m*n) | Space:O(m*n)
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {

        //true is for UP and false is for DOWN
        bool direction = true;

        if (matrix.size() == 0)
            return {};

        int m = matrix.size();
        int n = matrix[0].size();

        int count = 1;
        int i = 0, j = 0;
        vector<int> ans = {};
        while (count <= m * n)
        {
            ans.push_back(matrix[i][j]);
            if (direction)
            {
                if ((i - 1) >= 0 && (j + 1) <= n - 1)
                {
                    i = i - 1;
                    j = j + 1;
                }
                else if (j < n - 1)
                {
                    j = j + 1;
                    direction = false;
                }
                else if (i < m - 1)
                {
                    i = i + 1;
                    direction = false;
                }
            }
            else
            {
                if (i < m - 1 && j > 0)
                {
                    i = i + 1;
                    j = j - 1;
                }
                else if (i < m - 1)
                {
                    i = i + 1;
                    direction = true;
                }
                else if (j < n - 1)
                {
                    j = j + 1;
                    direction = true;
                }
            }
            count++;
        }
        return ans;
    }
};
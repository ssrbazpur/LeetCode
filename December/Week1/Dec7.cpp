class Solution
{
public:
    //Time:O(n*n) | Space:O(n*n)
    void updateMatrix(vector<vector<int>> &ans)
    {

        int row1 = 0;
        int row2 = ans.size() - 1;
        int col1 = 0;
        int col2 = ans[0].size() - 1;

        int val = 1;
        while (row1 <= row2 && col1 <= col2)
        {

            //First row
            for (int i = col1; i <= col2; i++)
            {
                ans[row1][i] = val;
                val++;
            }

            //Last Col
            for (int i = row1 + 1; i <= row2; i++)
            {
                ans[i][col2] = val;
                val++;
            }

            //Last row
            for (int i = col2 - 1; i >= col1; i--)
            {
                if (row1 == row2)
                    break;
                ans[row2][i] = val;
                val++;
            }

            //First Col
            for (int i = row2 - 1; i >= row1 + 1; i--)
            {

                if (col1 == col2)
                    break;
                ans[i][col1] = val;
                val++;
            }
            row1++;
            row2--;
            col1++;
            col2--;
        }
    }
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        updateMatrix(ans);
        return ans;
    }
};
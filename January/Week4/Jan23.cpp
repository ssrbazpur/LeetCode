class Solution
{
public:
    //Time: O( m*n * log(d)) where d is length of diagonal
    //sPACE: o(m*n)
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {

        //Min Heap.
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hm;

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                int dig = i - j;
                if (hm.find(dig) != hm.end())
                {
                    hm[dig].push(mat[i][j]);
                }
                else
                {
                    priority_queue<int, vector<int>, greater<int>> q;
                    q.push(mat[i][j]);
                    hm.insert({dig, q});
                }
            }
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                int dig = i - j;
                int value = hm[dig].top();
                mat[i][j] = value;
                hm[dig].pop();
            }
        }
        return mat;
    }
};
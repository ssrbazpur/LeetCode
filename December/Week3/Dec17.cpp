class Solution
{
public:
    //Time:O(N^2)
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {

        unordered_map<int, int> hm;
        for (int a : A)
        {
            for (int b : B)
            {
                hm[a + b]++;
            }
        }
        int ans = 0;
        for (int c : C)
        {
            for (int d : D)
            {

                if (hm.find(-c - d) != hm.end())
                {
                    ans += hm[-c - d];
                }
            }
        }
        return ans;
    }
};
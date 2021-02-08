class Solution
{
public:
    //TC: O(N) //Space:O(n)
    vector<int> shortestToChar(string s, char c)
    {

        vector<int> ans(s.size(), INT_MAX);

        int val = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                val = 0;
                ans[i] = val;
            }
            else
            {
                if (val != -1)
                {
                    val++;
                    ans[i] = val;
                }
            }
        }

        val = INT_MAX;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == c)
            {
                val = 0;
                ans[i] = val;
            }
            else
            {
                if (val != INT_MAX)
                {
                    val++;
                    ans[i] = min(ans[i], val);
                }
            }
        }

        return ans;
    }
};
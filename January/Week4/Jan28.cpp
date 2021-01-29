class Solution
{
public:
    //TC:O(n) | SC:O(N)
    string getSmallestString(int n, int k)
    {
        vector<char> ans(n);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (k - i >= 26)
            {
                ans[i] = 'z';
                k = k - 26;
            }
            else
            {
                if (i == 0)
                {
                    int val = k - 1 + 'a';
                    char c = (char)val;
                    ans[i] = c;
                    break;
                }
                int j = 0;
                for (j = 0; j < i; j++)
                {
                    ans[j] = 'a';
                    k--;
                }
                int val = k - 1 + 'a';
                char c = (char)val;
                ans[j] = c;
                break;
            }
        }
        string ans1 = "";
        for (char a : ans)
        {
            ans1 += a;
        }
        return ans1;
    }
};
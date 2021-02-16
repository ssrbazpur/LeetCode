class Solution
{
public:
    //TC: O(2^n)  and SC :O(2^n * n)
    void helper(string s, int p, vector<string> &ans)
    {

        if (p == s.size())
        {
            ans.push_back(s);
            return;
        }

        char ch = s[p];
        helper(s, p + 1, ans);
        char newch = s[p];
        if (!(ch >= '0' && ch <= '9') && islower(ch))
        {
            newch = toupper(ch);
        }
        else if (!(ch >= '0' && ch <= '9') && isupper(ch))
        {
            newch = tolower(ch);
        }
        s[p] = newch;
        if (!(ch >= '0' && ch <= '9'))
            helper(s, p + 1, ans);
        s[p] = ch;
    }

    vector<string> letterCasePermutation(string S)
    {
        vector<string> ans;
        helper(S, 0, ans);
        return ans;
    }
};
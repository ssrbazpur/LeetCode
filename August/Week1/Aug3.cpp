class Solution
{
public:
    //Time:O(N) | Space:O(1)
    bool isPalindrome(string s)
    {
        int start = 0;
        int last = s.size() - 1;
        while (start < last)
        {

            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[last]))
            {
                last--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[last]))
                return false;
            start++;
            last--;
        }

        return true;
    }
};
class Solution
{
public:
    //Time:O(N) | Space:O(1)
    bool detectCapitalUse(string word)
    {
        int count = 0;
        for (char a : word)
        {
            if (a >= 'A' && a <= 'Z')
                count++;
        }

        if (count == 0 || (isupper(word[0]) && count == 1) || count == word.size())
        {
            return true;
        }
        return false;
    }
};
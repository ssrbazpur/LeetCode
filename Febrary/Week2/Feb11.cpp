class Solution
{
public:
    //TC:O(N) | SC:O(1)
    bool isAnagram(string s, string t)
    {

        vector<int> store(26, 0);
        for (char a : s)
        {
            int index = a - 'a';
            store[index]++;
        }

        for (char b : t)
        {
            int index = b - 'a';
            store[index]--;
        }

        for (int i = 0; i < store.size(); i++)
        {
            if (store[i] != 0)
                return false;
        }
        return true;
    }
};
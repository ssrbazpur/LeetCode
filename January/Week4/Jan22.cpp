class Solution
{
public:
    //Time:O(max(word1,word2)) Space:O(1) as only 26 characters are there
    bool closeStrings(string word1, string word2)
    {

        //1. Both should have same characters
        //2. There must be some Freq in 2nd to match first.

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        unordered_set<int> c1;
        unordered_set<int> c2;

        for (char a : word1)
        {
            freq1[a - 'a']++;
            c1.insert(a);
        }

        for (char a : word2)
        {
            freq2[a - 'a']++;
            c2.insert(a);
        }

        unordered_set<int> f1;
        unordered_set<int> f2;

        for (int a : freq1)
        {
            f1.insert(a);
        }

        for (int a : freq2)
        {
            f2.insert(a);
        }

        return c1 == c2 && f1 == f2;
    }
};

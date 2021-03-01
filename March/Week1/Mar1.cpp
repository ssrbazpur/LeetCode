class Solution
{
public:
    //TC:O(N) | SC:O(N)
    int distributeCandies(vector<int> &candyType)
    {

        unordered_set<int> hm;

        for (int candy : candyType)
        {
            hm.insert(candy);
        }
        int n = candyType.size() / 2;

        if (hm.size() <= n)
        {
            return hm.size();
        }
        else
        {
            return n;
        }
    }
};
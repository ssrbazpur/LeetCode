/*

[1,0,0,0,1,0,0,1], k = 2
c=2


*/

//TC:O(N) | SC:o(1)
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int startIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                startIndex = i;
                break;
            }
        }
        int counter = 0;
        for (int i = startIndex + 1; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (counter < k)
                {
                    return false;
                }
                counter = 0;
            }
            else
            {
                counter++;
            }
        }

        return true;
    }
};
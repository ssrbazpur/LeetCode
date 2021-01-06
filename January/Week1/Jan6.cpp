class Solution
{
public:
    //Space:O(1) | Time:O(N)
    int findKthPositive(vector<int> &arr, int k)
    {

        int start = 1;
        for (int i = 0; i < arr.size(); i++)
        {

            while (start != arr[i])
            {
                k--;
                if (k == 0)
                    return start;
                start++;
            }
            start++;
        }

        return start + k - 1;
    }
};
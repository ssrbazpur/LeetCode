class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {

        int maxValue = INT_MIN;
        int minValue = INT_MAX;

        if (nums.size() == 1)
            return 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (i == 0 && nums[i] > nums[i + 1])
            {
                maxValue = max(maxValue, nums[i]);
                minValue = min(minValue, nums[i]);
            }
            else if (i == nums.size() - 1 && nums[i] < nums[i - 1])
            {
                maxValue = max(maxValue, nums[i]);
                minValue = min(minValue, nums[i]);
            }
            else if (i > 0 && i < nums.size() - 1)
            {
                if (nums[i] < nums[i - 1] || nums[i] > nums[i + 1])
                {
                    maxValue = max(maxValue, nums[i]);
                    minValue = min(minValue, nums[i]);
                }
            }
        }

        int ans = 0;
        if (maxValue == INT_MIN || minValue == INT_MAX)
            return ans;

        int l = 0, r = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > minValue)
            {
                l = i;
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {

            if (nums[i] < maxValue)
            {
                r = i;
                break;
            }
        }

        return r - l + 1;
    }
};

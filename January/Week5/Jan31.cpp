class Solution
{
public:
    //TC:O(N) | SC:O(1)
    void nextPermutation(vector<int> &nums)
    {

        if (nums.size() == 0)
            return;
        int p = nums.size() - 2;
        bool complete = false;
        int val = nums[nums.size() - 1];
        while (p >= 0)
        {
            if (nums[p] < nums[p + 1])
            {
                complete = true;
                break;
            }
            p--;
        }

        if (complete == true)
        {
            int second = p + 1;
            while (second < nums.size() && nums[second] > nums[p])
            {
                second++;
            }
            int temp = nums[second - 1];
            nums[second - 1] = nums[p];
            nums[p] = temp;
        }
        int start = p + 1;
        int end = nums.size() - 1;
        while (start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};
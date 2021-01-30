
/*

[4,1,5,20,3]
[4,2,10,5,3]

Double odd numbers and put all numbers into a max heap. Track the smallest number. Track the minimum difference between the top of the heap and the smallest number. While the top of the heap is even, remove it, divide, and put back to the heap.

*/

//TC:O(NLogN) } Space:O(N)
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {

        //Max Heap
        priority_queue<int> q;

        int minVal = INT_MAX;
        for (int a : nums)
        {
            int val = a % 2 == 0 ? a : a * 2;
            q.push(val);
            minVal = min(minVal, val);
        }
        int res = INT_MAX;

        while (q.top() % 2 == 0)
        {
            res = min(res, q.top() - minVal);
            minVal = min(q.top() / 2, minVal);

            q.push(q.top() / 2);
            q.pop();
        }

        return min(res, q.top() - minVal);
    }
};
/*

Conceptual Overview:

1. int left=getLeftIndex of Lower Element than current (Use stack)
2. int right=getRightIndex of Lower Element than current (Use stack)
3. Area= (right-left-1)*height

Time:O(N)
Space:O(N)

*/

class Solution
{

private:
    vector<int> getLeftIndex(vector<int> &heights)
    {

        vector<int> ans(heights.size(), -1);
        stack<int> s; //store the indexes

        for (int i = 0; i < heights.size(); i++)
        {

            int currVal = heights[i];
            while (!s.empty() && heights[s.top()] >= currVal)
            {
                s.pop();
            }

            if (!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> getRightIndex(vector<int> &heights)
    {

        vector<int> ans(heights.size(), heights.size());
        stack<int> s; //store the indexes

        for (int i = heights.size() - 1; i >= 0; i--)
        {

            int currVal = heights[i];
            while (!s.empty() && heights[s.top()] >= currVal)
            {
                s.pop();
            }

            if (!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

public:
    //Time:O(n) and Space:O(n)
    int largestRectangleArea(vector<int> &heights)
    {

        vector<int> leftIndex = getLeftIndex(heights);
        vector<int> rightIndex = getRightIndex(heights);

        int area = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int tempArea = (rightIndex[i] - leftIndex[i] - 1) * heights[i];
            area = max(tempArea, area);
        }

        return area;
    }
};
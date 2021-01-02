class Solution
{
public:
    //Time:O(N) | Space:O(1)
    bool validMountainArray(vector<int> &arr)
    {

        for (int i = 1; i < arr.size() - 1; i++)
        {

            //If peak found than stricktly decearsing arr[i]>=arr[i-1]
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
            {
                i++;
                while (i < arr.size())
                {
                    if (arr[i] >= arr[i - 1])
                        return false;
                    i++;
                }
                if (i == arr.size())
                    return true;
            }

            //Else check for Strickly Increasing arr[i]>arr[i-1] && arr[i+1]>arr[i]
            if (arr[i] <= arr[i - 1] || arr[i] >= arr[i + 1])
                return false;
        }

        return false;
    }
};
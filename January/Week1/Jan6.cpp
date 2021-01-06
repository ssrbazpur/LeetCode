class Solution
{
public:
    //Space:O(1) | Time:O(logN)
    int findKthPositive(vector<int> &arr, int k)
    {

        int left = 0;
        int right = arr.size(); //Tricky Line

        while (left < right)
        {

            int mid = left + (right - left) / 2;
            if (arr[mid] - (mid + 1) >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << left << " " << right;

        return right + k;
        //         int start=1;
        //         for(int i=0;i<arr.size();i++){

        //             while(start!=arr[i]){
        //                 k--;
        //                 if(k==0) return start;
        //                 start++;
        //             }
        //             start++;
        //         }

        //         return start+k-1;
    }
};
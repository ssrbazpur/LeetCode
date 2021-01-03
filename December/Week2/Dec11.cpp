/*
Conceptual Overview:
Time:O(N) | Space:O(1)
*/

class Solution
{
public:
    //Time:O(N) and Space:O(1)
    int removeDuplicates(vector<int> &nums)
    {

        // int i = 0;
        // for (int n : nums){
        //     if (i < 2 || n > nums[i-2]) nums[i++] = n;
        // }
        // return i;

        int p = 0;
        int i = 0;
        while (i < nums.size())
        {
            int start = i;

            //Start start and End Pointer i
            while (i < nums.size() && nums[start] == nums[i])
            {
                i++;
            }

            int len = i - start;
            int freq = min(len, 2);

            while (freq > 0)
            {
                nums[p] = nums[start];
                p++;
                freq--;
            }
        }

        return p;

        //         if(nums.size()==0) return 0;
        //         int val=nums[0];
        //         int count=1;
        //         for(int i=1;i<nums.size();i++){

        //             if(nums[i]==val){
        //                 count++;
        //             }else{
        //                 count=1;
        //                 val=nums[i];
        //             }

        //             if(count>2){
        //                 nums.erase(nums.begin()+i);
        //                 i=i-1;
        //                 continue;
        //             }
        //         }

        //         return nums.size();
    }
};
//Space:O(1) and Time:O(log N)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
       int start=0;
        int last=nums.size()-1;
        
        while(start<last){
            if(nums[start]!=nums[start+1]){
                break;
            }
            if(nums[last]!=nums[last-1]){
                start=last;
                break;
            }
            
            if(nums[start]==nums[start+1]){
                start=start+2;
            }
            if(nums[last]==nums[last-1]){
                last=last-2;
            }
            
        }
        
        return nums[start];
    }
};

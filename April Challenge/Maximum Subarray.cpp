//Time:O(n) and Space:O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
      int sum=nums[0];
      int track=nums[0];
      for(int i=1;i<nums.size();i++){
      track=max(nums[i],track+nums[i]);
      if(track>sum){
      sum=track;
      }
      }
       return sum; 
    }
};

//Time:O(n) and Space:O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* WHEN ORDER DOES NOT MATTER
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            if(nums[start]==0){
                swap(nums[start],nums[end]);
                end--;
            }
            start++;
        }
        */
       int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[zero]);
                zero++;
            }  
        }
    } 
        
};

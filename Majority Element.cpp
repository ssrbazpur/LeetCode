class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
       //Boyer Moore
        int count=0;
        int candidate=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate=nums[i];
            }
            count=count+((nums[i]==candidate)?1:-1);
        }
        return candidate;
    }
};

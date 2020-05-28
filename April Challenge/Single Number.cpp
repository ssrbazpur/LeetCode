//Time:O(n) and Space:O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int result=0;
        
        for(int i=0;i<nums.size();i++){
            
            result=result^nums[i];
            
            
            
        }
        return result;
    }
    /*
    unordered_map<int,int> hm;
       for(int i=0;i<nums.size();i++){
           if(hm.find(nums[i])!=hm.end()){
               hm[nums[i]]++;
           }else{
               hm.insert(make_pair(nums[i],1));
           }
       } 
        for(auto i=hm.begin();i!=hm.end();i++){
            if(i->second==1){
                return i->first;
            }
        }
        */
};

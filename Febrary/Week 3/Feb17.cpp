class Solution {
public:
    //TC:O(N) | SC:O(1)
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        
        int ans=0;
        
        while(left<right){
            
            int width= right - left;
            int area= height[left] < height[right] ? width * height[left] : width * height[right];
            ans=max(ans,area);

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
    
        return ans;
        
    }
};
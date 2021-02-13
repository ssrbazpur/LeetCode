class Solution {
public:
    int numberOfSteps (int num) {
        int ans=0;
        while(num!=0){
            
            if(num%2!=0){
                ans++;
                num=num-1;
            }
            if(num==0) return ans;
            
            num=num/2;
            ans++;
        }
        return ans;
        
    }
};
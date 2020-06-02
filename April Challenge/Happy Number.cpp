class Solution {
public:
    
 int f(int n){
        int ans=0;
        while(n>0){
            int digit=n%10;
            ans+=digit*digit;
            n=n/10;
        }
        
        return ans;
    }
    
bool isHappy(int n) {
       
       int slow=n;
       int fast=n;
       do{
       slow=f(slow);
       fast=f(fast);
       fast=f(fast);
       }while(slow!=fast);
       return fast==1;
    }
};

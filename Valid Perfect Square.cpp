class Solution {
public:
    bool isPerfectSquare(int num) {
        
        
        
        if(num==1) return true;
      
        
        int left=0,right=num;
        
        while(left<=right){
            int mid=left+ (right-left)/2;
            float a=(float)num/mid;
            cout<<a;
            if(a==(float)mid) return true;
            else if(a<(float)mid){right=mid-1;}
            else{
                left=mid+1;
            }
            
            
        }
        
        return false;
        
    }
};

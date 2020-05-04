class Solution {
public:
    
    vector<int> getbinary(int num){
        
        //5 ->   101 
        //8 -> 100
        vector<int> store;
        while(num>0){
            store.push_back(num%2);
            num=num/2;
        }
        return store;
        
    }
    int findComplement(int num) {
        
        vector<int> binary=getbinary(num);
        int a=0;
        string ans="";
        int k=0;
        
        //1 -> 10 + 0 = 10 ;  5- 101 ->10
        
        for(int i=binary.size()-1;i>=0;i--){
            
            
            if(binary[i]==1){
                ans=ans+'0';
            }
            else{
                ans=ans+'1';
               
            }
        }
         
       for(int i=ans.size()-1;i>=0;i--){
           
           if(ans[i]=='1'){
               a+=pow(2,k);
           }
           k++;
       }
        
        cout<<a;
        
            return a;
        
        
    }
};

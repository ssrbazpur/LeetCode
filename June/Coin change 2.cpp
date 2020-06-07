/*
amount = 5, coins = [1, 2, 5]

[1,0,0,0,0,0]
then if(i>=coin) then a[i]=a[i]+a[i-coin]

*/

//Time: O(n*amount) Space:O(amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> store(amount+1,0);
        store[0]=1;
        for(int coin:coins){
            for(int i=0;i<store.size();i++){
                if(i>=coin){
                   store[i]=store[i-coin]+store[i]; 
                }
            }
        }
        return store.back();
    }
};

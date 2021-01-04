## Notes

### Week 1
* Dec 1: Easy
* Dec 2: Tricky: Reservoir Sampling Question
* Dec 3: Tricky: Inorder Traveral. Make dummy pointer p. Do Inorder Traversal. Algo: F(L) node->left=NULL; p->right=node p=node F(R)
* Dec 4: Tricky: Note i and n/i are two factor if (n%i==0). Iterate till i=1 to i< sqrt(n) and then from i=sqrt(n) to i>=1.
* Dec 5: Easy. If a[i]==1 then skip. If a[i]==0 then check that adjacent are vacant. If yes then place the flower.
* Dec 6: Tricky: Binary Tree (BFS and make last node of each level point to NULL)
* Dec 7: Easy. col1 , col2, row1, row2. while(ro1<=row2 && col1<=col2)

### Week 2
* Dec 8: Tricky Easy: Make a array[60]. Then for each number check that there exists a index in array that adds to 60. 
* Dec 9: Easy: Store inorder Traversal and then maintain a pointer to keep track of next.
* Dec 10: Easy Array.
* Dec 11: Easy Tricky. Make a pointer p. Calculate len by start and end pointer and append only two value using p if greater than 2.
* Dec 12: Tricky: If leftdepth==rightdepth return node else return greater depth node.
* Dec 13: Very Hard: Recursion and Memorization: dp[i][j]->burst balloons from i to j. 

        ```
        // Solution 1:
        function(nums,left,right,dp):
            if(left<0 || left>right || right>nums.size()-1) return 0;
            if(dp[left][right]!=null) return dp[left][right]
            int ans=INT_MIN;
            for(int i=left;i<=right;i++){
                int lval=left-1<0?1:nums[left-1];
                int rval=right+1>nums.size()-1?1:nums[right-1];
                ans=max(ans,nums[i]*lval*rval+function(nums,left,i-1,dp))+function(nums,i+1,right,dp);
            }
            return ans;

       ```
* Dec 14: Hard: Make an index and store in result as soon as it equals size of string.

        ```
        //Time:O(N*2^N) | Space:O(N)
        dfs(index,string,tempPath,path):
            if(index==string.size()-1) path.append(tempPath)

            for(int i=index;i<string.size();i++){
                if(isPalindrome(string,index,i)){
                    tempPath.append(string.substr(index,i-index+1));
                    dfs(index+1,string,tempPath,path);
                    tempPath.pop_back();
                }
            }
        ```

### Week 3

* Dec 15
* Dec 16
* Dec 17
* Dec 18
* Dec 19
* Dec 20
* Dec 21



### Week 5
* Dec 30: Masking of Numbers 
* Dec 31: getImmediateLeftLower and getImmediateRightLower by using Stack.


### January

## Week 1

* Jan 1: Easy: HashMap Use. First Value of arr as key and rest as values
* Jan 2: Easy: Simple Inorder Traversal of two tree. Return node if it is equal to target 
* Jan 3: Medium Tricky: Permutation Algorithm plus one addition check.
* Jan 4: Easy: Make a dummy node and two pointers for both linked list.
* Jan 5: Easy : Make dummy and check if duplication or not. 
* Jan 6: Easy: Make a start=1 and check it in array[i] if not equal decrement k. When k is zero there is the ans.
* Jan 7: Easy Question but tricky with using Pointers. 

    ``` 
    To Sort by second index.
    bool static compare(vector<int> &a,vector<int> &b){
        return a[1]>b[1];
    }

    vector<vector<int>> a;
    sort(a.begin(),a.end(),compare);
    
    ```
 
 ## Week 2

 * Jan 9: Note: BFS to be done for finding shortest path between source and destination. Call q.front() and q.pop() inside while loop
 * Jan 10: Fenwick Tree : 1. Array size is no of elements + 2. 0 index does not store anything. getParent can be done by just inverting the last set bit. 


 ## Week 4

  * Jan 23: unordered_map<int, priority_queue<int,vector<int>,greater<int>>> where key is i-j and value is element in that diagonal (Min Heap).

    ```
    //Priority Queue

    1. Min Heap - priority_queue<int,vector<int>,greater<int>> q;
    2. Max Heap - priority_queue<int>
    3. Compare :
        class Point
        {
            public:
            int x;
            int y;
        };

        class myComparator{

            public:
            int operator()(const Point& p1, const Point& p2)
            {
                return p1.x > p2.x;
            }
        };
        priority_queue<int,vector<int>,myComparator> q


    ```
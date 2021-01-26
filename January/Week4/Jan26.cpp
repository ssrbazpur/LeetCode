class Effort
{

public:
    int row;
    int col;
    int effort;
};

//Time:O(N*M*LOG(N*M)) SC:O(N*M)
class myComparator
{

public:
    // int operator()(const vector<int>& p1, const vector<int>& p2)
    //        {
    //            return p1[2] > p2[2];
    //        }

    int operator()(const Effort *p1, const Effort *p2)
    {
        return p1->effort > p2->effort;
    }
};

class Solution
{
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>> &heights)
    {

        vector<vector<int>> dp(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        dp[0][0] = 0;

        priority_queue<Effort *, vector<Effort *>, myComparator> q;

        // priority_queue<vector<int>,vector<vector<int>>,myComparator> q;

        Effort *e = new Effort();

        e->row = 0;
        e->col = 0;
        e->effort = 0;
        q.push(e);

        //q.push(vector<int>{0,0,0});

        while (!q.empty())
        {

            // vector<int> a=q.top();

            Effort *a = q.top();
            q.pop();

            int currow = a->row;
            int currcol = a->col;
            int currEffort = a->effort;

            // int currow=a[0];
            // int currcol=a[1];
            // int currEffort=a[2];

            if (currow == heights.size() - 1 && currcol == heights[0].size() - 1)
            {
                return currEffort;
            }

            for (int i = 0; i < 4; i++)
            {

                int newRow = currow + dir[i];
                int newCol = currcol + dir[i + 1];

                if (newRow >= 0 && newRow < heights.size() && newCol >= 0 && newCol < heights[0].size())
                {

                    int nextEffort = max(currEffort, abs(heights[currow][currcol] - heights[newRow][newCol]));

                    if (nextEffort < dp[newRow][newCol])
                    {
                        dp[newRow][newCol] = nextEffort;
                        // vector<int> temp={newRow,newCol,nextEffort};

                        Effort *temp = new Effort();
                        temp->row = newRow;
                        temp->col = newCol;
                        temp->effort = nextEffort;
                        q.push(temp);
                    }
                }
            }
        }

        return 0;
    }
};
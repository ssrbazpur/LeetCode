class Solution
{
public:
    //Time & Space: O(N)
    int minJumps(vector<int> &arr)
    {

        unordered_map<int, vector<int>> hm;

        for (int i = 0; i < arr.size(); i++)
        {
            if (hm.find(arr[i]) != hm.end())
            {
                hm[arr[i]].push_back(i);
            }
            else
            {
                hm.insert({arr[i], vector<int>{i}});
            }
        }

        vector<int> visited(arr.size(), 0);
        queue<int> q;
        q.push(0);
        int ans = 0; //level

        while (!q.empty())
        {
            int l = q.size();
            cout << l;
            while (l-- > 0)
            {

                int f = q.front();
                q.pop();
                if (f == arr.size() - 1)
                    return ans;

                if (f < 0 || f > arr.size() - 1 || visited[f])
                {
                    continue;
                }

                if ((f - 1 > 0) && !visited[f - 1])
                    q.push(f - 1);

                if ((f + 1 < arr.size()) && !visited[f + 1])
                {
                    q.push(f + 1);
                }

                if (hm.find(arr[f]) != hm.end())
                {

                    for (int index : hm[arr[f]])
                    {
                        if (index >= 0 && index < arr.size() && !visited[index])
                        {
                            q.push(index);
                        }
                    }
                    hm.erase(arr[f]);
                }

                visited[f] = true;
            }
            ans++;
        }

        return -1;
    }
};
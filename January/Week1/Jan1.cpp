// Let m and n be the no of elements in arr and pieces
//As length are equal we can take only n
//TC: O(max(m,n))
//SC: O(n)

class Solution
{

private:
    unordered_map<int, vector<int>> hm;

public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {

        //Forming the Map
        for (vector<int> p : pieces)
        {
            hm.insert({p[0], {}});
            for (int i = 1; i < p.size(); i++)
            {
                hm[p[0]].push_back(p[i]);
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (hm.find(arr[i]) != hm.end())
            {
                vector<int> num = hm[arr[i]];
                for (int j = 0; j < num.size(); j++)
                {
                    if (arr[++i] != num[j])
                        return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
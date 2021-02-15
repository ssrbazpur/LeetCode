class Solution
{
public:
    bool static compare(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first < b.first)
        {
            return true;
        }
        else if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return false;
    }

    //Get last position of 1
    int getSoldiers(vector<int> array)
    {
        int start = 0;
        int end = array.size();

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (array[mid] == 0)
            {
                end = mid - 1;
            }
            else
            {
                if (mid < array.size() - 1 && array[mid + 1] == 0)
                {
                    return mid;
                }
                else if (mid < array.size() - 1 && array[mid + 1] == 1)
                {
                    start = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
        }
        return end;
    }

    //Time : M * N
    //O( M * log N + M * log M)
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        vector<pair<int, int>> soldiers;

        for (int i = 0; i < mat.size(); i++)
        {
            int n = getSoldiers(mat[i]);
            cout << n << endl;
            soldiers.push_back({n, i});
        }

        sort(soldiers.begin(), soldiers.end(), compare);

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(soldiers[i].second);
        }

        return ans;
    }
};
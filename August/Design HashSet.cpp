class MyHashSet
{
public:
    /** Initialize your data structure here. */
    vector<vector<int>> map;
    //Name it capacity
    //Load Factor = n/k where n is 100000 k is 150000 as it should be less than 1.0
    int key = 15000;

    int getHash(int val)
    {
        return val % key;
    }

    MyHashSet()
    {
        map = vector<vector<int>>(key, vector<int>{});
    }

    void add(int key)
    {
        int hashValue = getHash(key);
        if (find(map[hashValue].begin(), map[hashValue].end(), key) == map[hashValue].end())
            map[hashValue].push_back(key);
    }

    void remove(int key)
    {
        int hashValue = getHash(key);
        if (map[hashValue].size() == 0)
        {
            return;
        }
        else
        {
            auto it = find(map[hashValue].begin(), map[hashValue].end(), key);
            if (it != map[hashValue].end())
            {
                map[hashValue].erase(it);
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int hashValue = getHash(key);
        if (map[hashValue].size() == 0)
        {
            return false;
        }
        for (int i = 0; i < map[hashValue].size(); i++)
        {
            if (map[hashValue][i] == key)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
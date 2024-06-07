class Solution {
public:
    void createHeap(vector<pair<int, int>>& v)
    {
        int n = v.size();
        for (int i = 2; i <= n; ++i)
        {
            Insert(v, i);
        }
    }
    void Insert(vector<pair<int, int>>& v, int n)
    {
        n = n-1;
        pair<int, int> temp;
        temp = v[n];
        int i = n;

        while (i > 0 && temp.second > v[(i-1) / 2].second)
        {
            v[i] = v[(i-1) / 2];
            i = (i-1) / 2;
        }
        v[i] = temp;
    }
    void Delete(vector<pair<int, int>>& v, int n)
    {
        n = n-1;
        int i,j;
        i = 0; j = 1;
        pair<int, int> x = v[0];
        v[0] = v[n];
        while (j < n)
        {
            if (v[j+1].second > v[j].second)
                j = j+1;
            
            if (v[i].second < v[j].second)
            {
                swap(v[i], v[j]);
                i = j;
                j = 2*j+1;
            }
            else
                break;
        }
        v[n] = x;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int n : nums)
        {
            mp[n]++;
        }
        vector<pair<int,int>> v;
        for (auto p : mp) 
        {
            v.push_back(p);
        }
        createHeap(v);
        
        int n = v.size();
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(v[0].first);
            Delete(v, n--);
            
        }
        return ans;
    }
};
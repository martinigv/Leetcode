class Solution {
public:
    void Insert(vector<int>& A, int n)
    {
        int temp;
        temp = A[n-1];
        int i = n-1;
        while (i > 0 && temp > A[(i-1) / 2])
        {
            A[i] = A[(i-1) / 2];
            i = (i-1) / 2;
        }
        A[i] = temp;
    }
    
    void createHeap(vector<int>& A)
    {
        int n = A.size();
        for (int i = 1; i < n; ++i)
        {
            Insert(A, i+1);
        }
    }
    void Delete(vector<int>& A, int n)
    {
        int x,i,j;
        x = A[n-1];
        A[0] = A[n-1];
        i = 0; j = 2*i+1;
        while (j < n)
        {
            if (j + 1 < n && A[j+1] > A[j])
            {
                j = j + 1;
            }
            if (A[i] < A[j])
            {
                swap(A[i], A[j]);
                i = j;
                j = 2*j+1;
            }
            else
                break;
        }
        A[n-1] = x;
    }
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for (int i = 0; i < items.size(); ++i)
        {
            mp[items[i][0]].push_back(items[i][1]);
        }
        for (auto pair : mp)
        {
            createHeap(pair.second);
            int sum = 0;
            int n = pair.second.size();
            for (int i = 0; i < 5; ++i)
            {
                sum += pair.second[0];
                Delete(pair.second, n);
                n--;
            }
            sum /= 5;
            ans.push_back({pair.first, sum});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    void Insert(vector<int>& A, int n)
    {
        n = n-1;
        int temp;
        temp = A[n];
        int i = n;
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
        for (int i = 2; i <= n; ++i)
        {
            Insert(A, i);
        }
    }
    void Delete(vector<int>& A, int n)
    {
        int x, i, j;
        i = 0; j = 1;
        n = n-1;
        x = A[i];
        A[i] = A[n];
        while (j < n)
        {
            if (j+1 < n && A[j+1] > A[j])
            {
                j = j + 1;
            }
            if (A[i] < A[j])
            {
                swap(A[i], A[j]);
                i = j;
                j = 2*j + 1;
            }
            else
                break;
        }
        A[n] = x;
    }
    int lastStoneWeight(vector<int>& stones) {
        createHeap(stones);

        int n = stones.size();
        while (n > 1)
        {
            int f = stones[0];
            Delete(stones, n--);
            int s = stones[0];
            Delete(stones, n--);
            
            if (f != s)
            {
                stones[n++] = f-s;
                Insert(stones, n);
            }
        }
        return n > 0 ? stones[0] : 0;
    }
};
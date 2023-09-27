class Solution {
public:
    vector<int>memory;
    vector<int>cost;
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        memory = vector<int>(cost.size() + 1, -1);
        return dp(cost.size());
    }
    int dp(int i) {
        if (i <= 1) {
            return 0;
        }
        if (memory[i] != -1) {
            return memory[i];
        }
        memory[i] = min(dp(i - 1) + cost[i - 1], dp(i - 2) + cost[i - 2]);
        return memory[i];
    }
};
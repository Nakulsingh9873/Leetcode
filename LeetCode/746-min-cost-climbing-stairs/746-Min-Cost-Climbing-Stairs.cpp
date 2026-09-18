class Solution {
public:
int solRec(vector<int>&cost, int i)
{
    if(i >= cost.size())
    {
        return 0;
    }
    int fst = solRec(cost, i + 1);
    int sst = solRec(cost, i + 2);
    return cost[i] + min(fst, sst);
}
int solMem(vector<int>&cost, int i,vector<int>&dp)
{
    if(i >= cost.size())
    {
        return 0;
    }
    if(dp[i] != -1)
    {
        return dp[i];
    }
    int fst = solMem(cost, i + 1, dp);
    int sst = solMem(cost, i + 2, dp);
    dp[i] = cost[i] + min(fst, sst);
    return dp[i];
}
    int minCostClimbingStairs(vector<int>& cost) {
        //return min(solRec(cost, 0), solRec(cost, 1));
        int n = cost.size();
        vector<int>dp(n, -1);
        return min(solMem(cost,0,dp), solMem(cost,1,dp));
    }
};
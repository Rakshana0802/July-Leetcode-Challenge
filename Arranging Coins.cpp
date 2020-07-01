class Solution 
{
public:
    int arrangeCoins(int n) 
    {
        return (sqrt(8*(long long)n+1)-1)/2;
    }
};

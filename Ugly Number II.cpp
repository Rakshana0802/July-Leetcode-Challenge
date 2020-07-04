class Solution
{
public:
    int nthUglyNumber(int n) 
    {
        int a = 0, b = 0, c = 0;
        vector<int> ugly_numbers(1690);
        ugly_numbers[0] = 1;
        for (int i = 1; i < n; ++i) 
        {
            int first = ugly_numbers[a] * 2;
            int second = ugly_numbers[b] * 3;
            int third = ugly_numbers[c] * 5;
            
            ugly_numbers[i] = min(first, min(second, third));
            if (ugly_numbers[i] == first) 
                a++;
            if (ugly_numbers[i] == second) 
                b++;
            if (ugly_numbers[i] == third) 
                c++;
        }
        return ugly_numbers[n-1];
    }
};

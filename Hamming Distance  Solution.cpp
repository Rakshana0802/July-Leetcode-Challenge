class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        int count = 0;
        int k = 32;
        while (k > 0 && x != y)
        {
            --k;
            if ((x & 1) != (y & 1))
            ++count;
            x = x >> 1;
            y = y >> 1;
        }
        return count;
    }
};

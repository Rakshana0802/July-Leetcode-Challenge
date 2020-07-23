class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xor_result = 0;
        for (int i=0;i < nums.size(); i++)
            xor_result = xor_result ^ nums[i];

        int pos = 0;
        while ((xor_result & (1 << pos)) == 0)
             pos++;

        int num1 = 0;
        for (int i=0;i < nums.size(); i++) 
        {
             if ((nums[i] & (1 << pos)) != 0)
                 num1 = num1 ^ nums[i];
        }
        
        int num2 = xor_result ^ num1;
        vector<int> result = {num1, num2};
        return result;
    }
};

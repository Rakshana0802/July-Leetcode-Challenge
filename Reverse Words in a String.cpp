class Solution 
{
public:
    string reverseWords(string s) 
    {
        auto sourceSize = s.size();
        string resultStr;
        resultStr.reserve(sourceSize);
        string str;
        str.reserve(sourceSize / 2 );
        auto concatStr = [](std::string &str1, std::string &str2)-> std::string 
        {
        if (str2.length() == 0)
            return str1;

        return str1 + " " + str2;
        };

        bool prevSymbol = false;
        for (auto &c : s) 
        {
            bool isSpace = isspace(c) != 0;
            if (isSpace && prevSymbol) 
            {
                resultStr = concatStr(str, resultStr);
                str = "";
                prevSymbol = false;
                continue;
            }
            else if (isSpace)
                continue;

            prevSymbol = true;
            str += c;
        }
        if (str.length() != 0) 
            resultStr = concatStr(str, resultStr);
        
        return resultStr;
    }
    void checkValue(string input, string expected)
    {
        auto result = reverseWords(input);
        if (result != expected) 
        {
            throw new runtime_error("Failed on \"" + input + "\" Expected: " + expected);
        }
    }
    
};

#include <string>
#include <iostream>
using std::string;
int util(char a)
    {
        switch(a)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

class Solution {
public:
    int romanToInt(string s)
    {   
        int ret = 0;
        for(int i = 0; i < s.size(); i++)
        {
            ret += util(s[i]);
            if(i && util(s[i - 1]) < util(s[i]))
                ret -= 2 * util(s[i - 1]);
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    string s{argv[1]};
    int ret = 0;
    Solution Sol;
    ret = Sol.romanToInt(s);
    std::cout << ret << std::endl;
    return 0;
}
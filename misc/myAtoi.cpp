#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int flag = 0, sgn = 1, i = 0;
        string str;
        for(i = 0; i < s.size() && !isDigit(s[i]); i++)
        {
            if(!flag && s[i] == '+')
                {flag = 1; sgn = 1; continue;}
            if(!flag && s[i] == '-')
                {flag = 1; sgn = -1; continue;}
            if(!std::isspace(s[i]))
                return 0;
        }
        if(i == s.size())
            return 0;
        for(i = i; i < s.size() && chartoDigit(s[i]) == 0; i++)
        {
            continue;
        }
        for(i = i; i < s.size() && isDigit(s[i]); i++)
        {
            str.push_back(s[i]);
        }
        if (str.size() > 10)
        {
            if(sgn > 0)
                return 2147483647;
            else
                return -2147483648;
        }
        if(str.size() == 10 && str >= "2147483648")
        {
            if(sgn > 0)
                return 2147483647;
            else
                return -2147483648;
        }
        int ret = 0;
        for(int j = str.size() - 1; j >= 0; --j)
        {
            ret += (chartoDigit(str[j]) * power(10, str.size() - j - 1));
        }
        return ret * sgn;
    }
    int power(int x, int power)
    {
        if(!power)
            return 1;
        int counter = 1, ret = x;
        while(counter < power)
        {
            ret *= x;
            counter++;
        }
        return ret;
    }
    int chartoDigit(char x)
    {
        switch(x)
        {
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            default:
                return 0;
        }
    }
    bool isDigit(char x)
    {
        switch(x)
        {
            case '0':
                return true;
            case '1':
                return true;
            case '2':
                return true;
            case '3':
                return true;
            case '4':
                return true;
            case '5':
                return true;
            case '6':
                return true;
            case '7':
                return true;
            case '8':
                return true;
            case '9':
                return true;
            default:
                return false;
        }
    }
};

int main(int argc, char** argv)
{
    Solution Sol;
    string s{argv[1]};
    auto ret = Sol.myAtoi(s);
    return 0;
}
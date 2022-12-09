#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::stringstream;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        static vector<string> ret;
        for(int i = 0; i < n; i++)
        {
            string str = "";
            if(i % 3 && i % 5)
            {
                stringstream ss;
                ss << i;
                str = ss.str();
            }
            if(!(i % 3))
                str + "Fizz";
            if(!(i % 5))
                str + "Buzz";
            ret.push_back(str);
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution Sol;
    int n = 0;
    sscanf(argv[1], "%d", &n);
    auto ret = Sol.fizzBuzz(n);
    return 0;
}
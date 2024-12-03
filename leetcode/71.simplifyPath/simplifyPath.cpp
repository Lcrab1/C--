#include <iostream>
#include <stack>
#include <string>
#include<vector>
#include<sstream>
using namespace std;

string simplifyPath(string path)
{
    string token; // token常用来表示一个独立的，可处理的字符串单元
    stringstream ss;
    vector<string> stack;

    while (getline(ss, token, '/'))
    {
        if (token == "" || token == ".")
            continue;
        else if (token == "..")
        {
            if (!stack.empty())
            {
                stack.pop_back();
            }
        }
        else
        {
            stack.push_back(token);
        }
    }

    string res = "/";
    for (int i = 0; i < stack.size(); i++)
    {
        res += stack[i];
        if (i != stack.size() - 1)
        {
            res += "/";
        }
    }
    return res;
}

int main()
{
    string path = "/home/user/Documents/../Pictures";
    string res = simplifyPath(path);
    cout << res << endl;
    system("pause");
}

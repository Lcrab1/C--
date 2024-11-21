#include <iostream>
#include <sstream>
using namespace std;

bool isPalindrome(string s)
{
    stringstream temp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 0x61 && s[i] <= 0x7A)
        {
            temp << s[i];
        }
        else if (s[i] >= 0x41 && s[i] <= 0x5A)
        {
            char tmp = s[i] + 0x20;
            temp << tmp;
        }
        else
        {
            continue;
        }
    }
    string res = temp.str();
    int l, r;
    l = 0;
    r = res.size() - 1;
    while (l < r)
    {
        if (res[l++] == res[r--])
            continue;
        return false;
    }
    return true;
}

int main()
{
    string test1 = "A man, a plan, a canal: Panama";
    if (isPalindrome(test1))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    system("pause");
}

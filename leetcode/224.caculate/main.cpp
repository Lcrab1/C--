#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

    int StringToInt(string &s)
    {
        int res = 0;
        int n = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            int num = s[i] - '0';
            for (int j = n - i - 1; j > 0; j--)
            {
                num = num * 10;
            }
            res += num;
        }
        return res;
    }

    void removeBlank(string &s)
    {
        int pos = s.find(" ");
        while (pos != -1)
        {
            s.replace(pos, 1, "");
            pos = s.find(" ");
        }
    }

    int calculate(string s)
    {
        int res = 0;
        vector<int> nums;
        vector<char> notes;
        removeBlank(s);
        int i = 0;
        if (s[i] == '-')
        {
            nums.push_back(0);
            i++;
        }
        bool flag = false;
        for (; i < s.length(); i++)
        {
            if (s[i] == ')' || s[i] == ' ')
                continue;
            if (s[i] == '(')
            {
                if (i + 1 < s.length() && s[i + 1] == '-')
                {
                    flag = true;
                    i += 1;
                }
                continue;
            }
            if (s[i] == '+' || s[i] == '-')
            {
                notes.push_back(s[i]);
                continue;
                
            }
            int j = i;
            int count = 0;
            while (s[j] >= '0' && s[j] <= '9')
            {
                count++;
                j++;
            }
            string Str = s.substr(i, count);
            int num = StringToInt(Str);
            nums.push_back(flag ? -num : num);
            i += (count - 1);
        }
        stack<int> stack;
        while (!nums.empty())
        {
            stack.push(nums.back());
            nums.pop_back();
        }

        for (char note : notes)
        {
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();
            if (note == '+')
                stack.push(num2 + num1);
            else
                stack.push(num1 - num2);
        }
        return stack.top();
    }



int main(){
    string s = "-2+ 1";
    int res = calculate(s);
    system("pause");
}
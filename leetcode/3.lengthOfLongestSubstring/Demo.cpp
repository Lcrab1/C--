#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;
// int lengthOfLongestSubstring(string s)
// {
//     // s的长度不为0时
//     int maxLen = 0;
//     int start = 0;
//     unordered_set<char> lookup;
//     //判断s的长度是否为0
//     if (s.size() == 0)
//     {
//         return 0;
//     }
//     for (int i = 0; i < s.size(); i++)
//     {
//         // lookup中包含该字符，去掉最左侧的字符直到不包含为止
//         while (lookup.count(s[i]) != 0)
//         {
//             lookup.erase(s[start]);
//             start++;
//         }
//         //若lookup中不含该字符，则添加
//         lookup.insert(s[i]);
//         maxLen = max(maxLen, (int)lookup.size());
//     }
//     return maxLen;
// }

int lengthOfLongestSubstring(string s)
{
    int maxLen = 0;
    unordered_map<char, int> map;
    int left = 0, right = left;

    while (right < s.length())
    {
        // right中的字符不在窗口中
        auto it = map.find(s[right]);
        if (it != map.end())
        {
            // right指向的字符在窗口中
            left = max(map[s[right]] + 1, left);
        }

        map[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

int main()
{
    int ret = lengthOfLongestSubstring("abba");
    cout << ret << endl;
    system("pause");
}



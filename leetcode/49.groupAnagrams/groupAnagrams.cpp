#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string, int> string2Bool;
    for (string str : strs)
        string2Bool[str] = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        vector<string> temp;
        if (string2Bool[strs[i]] > 0)
            continue;
        string2Bool[strs[i]] = true;
        temp.push_back(strs[i]);
        unordered_map<char, int> charCount;
        for (int j = 0; j < strs[i].length(); j++)
            charCount[strs[i][j]]++;

        for (int j = i + 1; j < strs.size(); j++)
        {
            int lengthI = strs[i].length();
            int lengthJ = strs[j].length();
            if (lengthI != lengthJ || string2Bool[strs[j]] == true)
                continue;
            unordered_map<char, int> tempMap = charCount;
            int k;
            for (k = 0; k < strs[j].length(); k++)
            {
                if (tempMap.find(strs[j][k]) == tempMap.end() || tempMap[strs[j][k]] <= 0)
                    break;
                tempMap[strs[j][k]]--;
            }
            if (k == strs[j].length())
            {
                string2Bool[strs[j]] = true;
                temp.push_back(strs[j]);
            }
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{
    vector<string> strs = {"", ""};
    vector<vector<string>> res = groupAnagrams(strs);

    system("pause");
}

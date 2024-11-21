#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (words.empty() || s.empty())
            return res;

        unordered_map<string, int> wordCount;
        for (const auto &word : words)
        {
            wordCount[word]++;
        }

        int wordNum = words.size();
        int wordLen = words[0].length();
        int totalLen = wordNum * wordLen;

        for (int i = 0; i < wordLen; i++)
        {
            int left = i, right = i, count = 0;
            unordered_map<string, int> window;
 
            while (right + wordLen <= s.length())
            {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.find(word) != wordCount.end())
                {
                    window[word]++; 
                    count++;

                    while (window[word] > wordCount[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordNum)
                    {
                        res.push_back(left);
                    }
                }
                else
                {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> result = solution.findSubstring(s, words);

    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
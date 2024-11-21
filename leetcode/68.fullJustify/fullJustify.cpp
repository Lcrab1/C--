#include <vector>
#include <string>
#include <queue>
#include <sstream> // Include stringstream
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        int eachBlanks = 0;
        int extraBlanks = 0;
        int totalBlanks = 0;

        queue<string> q;
        int blanks = 0;
        int wordLength = 0;

        for (int i = 0; i < words.size(); i++)
        {
            string cur = words[i];
            if (wordLength + cur.length() + blanks <= maxWidth)
            {
                q.push(cur);
                blanks++;
                wordLength += cur.length();
            }
            else
            {
                bool onlyOne = false;
                if (q.size() == 1)
                {
                    onlyOne = true;
                }
                if (!onlyOne)
                    blanks--;
                totalBlanks = maxWidth - wordLength;
                eachBlanks = totalBlanks / blanks;
                extraBlanks = totalBlanks % blanks;

                stringstream temp; // Create a stringstream for the current line
                while (!q.empty())
                {
                    temp << q.front(); // Add the word to the stringstream
                    q.pop();

                    // Add spaces between words
                    if (!q.empty() || onlyOne)
                    {
                        for (int j = 0; j < eachBlanks; j++)
                            temp << " ";
                    }

                    if (extraBlanks-- > 0) // Distribute extra spaces
                        temp << " ";
                }
                res.push_back(temp.str()); // Convert stringstream to string and add to result
                q.push(cur);
                blanks = 1;
                wordLength = cur.length();
            }
        }

        // Handle the last line (left-justified)
        stringstream lastLine; // Create a stringstream for the last line
        while (!q.empty())
        {
            lastLine << q.front(); // Add the word to the last line
            q.pop();
            if (!q.empty())
                lastLine << " "; // Add a space if there's another word
        }

        // Right pad with spaces for the last line
        string lastStr = lastLine.str();
        lastStr.append(maxWidth - lastStr.length(), ' '); // Right pad with spaces
        res.push_back(lastStr);

        return res;
    }
};

#include <iostream>

int main()
{
    Solution sol;
    vector<string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth = 16;
    vector<string> justifiedText = sol.fullJustify(words, maxWidth);

    for (const string &line : justifiedText)
    {
        cout << "\"" << line << "\"" << endl;
    }

    system("pause");
}

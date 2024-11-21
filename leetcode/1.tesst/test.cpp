#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

bool EraseExistingSum(std::vector<int> &possibleNum, std::vector<int> &copySums, int newNum)
{
    for (int i = 0; i < possibleNum.size() - 1; i++)
    {
        int sum = possibleNum[i] + newNum;
        auto it = std::find(copySums.begin(), copySums.end(), sum);
        if (it != copySums.end())
        {
            copySums.erase(it);
        }
        else ///若possibleNum求和得到的值再sums中找不到，那说明possibleNum的值存在错误
        {
            return false;
        }
    }
    return true; // 所有的已知num之和都能在sums中找到
}

std::string solution(int n, std::vector<int> sums)
{
    // 先将sums排序
    std::sort(sums.begin(), sums.end());
    int len = sums.size();
    for (int i = 2; i < len; i++)
    {
        int x1 = (sums[0] + sums[1] - sums[i]) / 2;
        if ((sums[0] + sums[1] - sums[i]) % 2 != 0)
            continue; // 确保x1是整数
        int x2 = sums[0] - x1;
        std::vector<int> copySums = sums;
        std::vector<int> possibleNum;
        possibleNum.push_back(x1);
        possibleNum.push_back(x2);
        int newNum = x2;
        while (EraseExistingSum(possibleNum, copySums, newNum))
        {
            if (copySums.empty())
                break;
            std::sort(copySums.begin(), copySums.end());
            newNum = copySums[0] - x1; // 去除所有和之后，copySums中的最小值是 x1 + x3
            possibleNum.push_back(newNum);
        }
        if (possibleNum.size() == n)
        {
            std::sort(possibleNum.begin(), possibleNum.end());
            std::stringstream res;
            for (int j = 0; j < n; j++)
            {
                if (j > 0)
                    res << " ";
                res << possibleNum[j];
            }
            return res.str();
        }
    }
    return "Impossible";
}

int main()
{
    // You can add more test cases here
    std::vector<int> sums1 = {1269, 1160, 1663};
    std::vector<int> sums2 = {1, 1, 1};
    std::vector<int> sums3 = {226, 223, 225, 224, 227, 229, 228, 226, 225, 227};
    std::vector<int> sums4 = {-1, 0, -1, -2, 1, 0, -1, 1, 0, -1};
    std::vector<int> sums5 = {79950, 79936, 79942, 79962, 79954, 79972, 79960, 79968, 79924, 79932};

    std::cout << (solution(3, sums1) == "383 777 886") << std::endl;
    std::cout << (solution(3, sums2) == "Impossible") << std::endl;
    std::cout << (solution(5, sums3) == "111 112 113 114 115") << std::endl;
    std::cout << (solution(5, sums4) == "-1 -1 0 0 1") << std::endl;
    std::cout << (solution(5, sums5) == "39953 39971 39979 39983 39989") << std::endl;

    return 0;
}
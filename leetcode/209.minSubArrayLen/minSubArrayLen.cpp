#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int res = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        int sum = 0;
        for (int j = i; j < len; j++)
        {
            sum += nums[j];
            if (sum >= target)
            {
                res = min(res, j - i + 1);
                break;
            }
        }
    }
    return res;
}

int main()
{
    int target = 7;
    vector<int> nums({2, 3, 1, 2, 4, 3});
    int res = minSubArrayLen(target, nums);
    system("pause");
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)
        return res;
    int i = 0;
    int k = nums.size() - 1;
    int j = 0;
    bool positive = false;
    while (i < k - 1)
    {
        if (nums[i] + nums[k] < 0)
        {
            j = k - 1;
            positive = false;
        }
        else
        {
            j = i + 1;
            positive = true;
        }

        while (j < k && nums[i] + nums[j] + nums[k] < 0)
            j++;
        while (j > i && nums[i] + nums[j] + nums[k] > 0)
            j--;

        if (i < j < k && nums[i] + nums[j] + nums[k] == 0)
        {
            res.push_back({nums[i], nums[j], nums[k]});
        }
        while (k > j && nums[k] == nums[k - 1])
            k--;
        while (i < j && nums[i] == nums[i + 1])
            i++;
        if (positive)
            k--;
        else
            i++;
    }
    return res;
}

int main()
{

    vector<int> nums = {-1,
                        0,
                        1,
                        2,
                        -1,
                        -4};
    vector<vector<int>> res = threeSum(nums);

    system("pause");
}

#include <iostream>
#include <vector>
#include <queue>

int maxSubArray(std::vector<int> &nums)
{
   std::queue<int> intQueue;
    int prev = 0, cur = 0, max = INT_MIN;
    int sum = 0;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        // intQueue.push(nums[i]);
        prev = cur;
        sum += nums[i];
        cur = sum;
        max = std::max(max, cur);
        if (cur > prev && prev < 0 || nums[i] <= 0 && nums[i] > prev)
        {
            std::queue<int> empty;
            intQueue.swap(empty);
            // intQueue.push(nums[i]);
            cur = nums[i];
            sum = cur;
            max = std::max(max, cur);
        }
        intQueue.push(nums[i]);
    }
    return max;
}

int main()
{
    std::vector<int> test = {-2, -1};
    int res = maxSubArray(test);
    system("pause");
}
#include <iostream>
#include <vector>

bool canPartition(std::vector<int>& nums)
{
    int totalSum = 0;
    for(int num : nums)
    {
        totalSum += num;
    }

    if(totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;
    int n = nums.size();
    std::vector<std::vector<bool>> dp(n + 1,std::vector<bool>(target + 1,false));

    for(int i = 0; i <= n; ++i)
    {
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= target; ++j)
        {
            if(j < nums[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][target];
}

int main()
{
    std::vector<int> nums = {1,13,2,14};
    std::cout<< (canPartition(nums) ? "true" : "false")<< std::endl;
    return 0;
}

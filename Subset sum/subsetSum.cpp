#include <iostream>
#include <vector>

bool subsetSum(std::vector<int>& nums,int target)
{
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

int main(){
    std::vector<int> nums = {2,5,3,12,9};
    int target = 13;

    if(subsetSum(nums,target))
    {
        std::cout<<"TRUE"<< std::endl;
    }
    else
    {
        std::cout<<"FALSE"<< std::endl;
    }
return 0;
}
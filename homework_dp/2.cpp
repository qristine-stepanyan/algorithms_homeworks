#include <iostream>
#include <vector>

int minOperations(int n)
{
    std::vector<int> dp(n + 1, -1); 
    dp[0] = 0; 

    for(int i = 1; i <= n; ++i)
    {
        if(dp[i] == -1 || dp[i] > dp[i - 1] + 1)
        {
            dp[i] = dp[i - 1] + 1;
        }
        if(i % 2 == 0)
        {
            if(dp[i / 2] == -1 || dp[i] == -1 || dp[i] > dp[i / 2] + 1)
            {
                dp[i] = dp[i / 2] + 1;
            }
        }
    }
    return dp[n];
}

int main()
{
    int n;
    std::cin>> n;
    std::cout<< minOperations(n)<< std::endl;
return 0;
}
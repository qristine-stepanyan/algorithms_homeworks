#include <vector>
#include <iostream>

void sortPairs(std::vector<std::vector<int>>& pairs)
{
    int n = pairs.size();
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(pairs[j][1] > pairs[j + 1][1])
            {
                swap(pairs[j],pairs[j + 1]);
            }
        }
    }
}

int findLongestChain(std::vector<std::vector<int>>& pairs)
{
    sortPairs(pairs);
    int n = pairs.size();
    std::vector<int> dp(n,1);
    int maxLength = 1;
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(pairs[j][1] < pairs[i][0])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLength = std::max(maxLength, dp[i]);
    }
    return maxLength;
}

int main()
{
    std::vector<std::vector<int>> pairs = {{1,2},{7,8},{4,5}};
    std::cout<< findLongestChain(pairs)<< std::endl;
    return 0;
}

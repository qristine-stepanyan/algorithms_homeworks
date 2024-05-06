#include <iostream>
#include <vector>
#include <string>

int minSteps(std::string str1,std::string str2)
{
    int m = str1.size();
    int n = str2.size();
    
    std::vector<std::vector<int>> dp(m + 1,std::vector<int>(n + 1,0));
    
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    
    int lCS_length = dp[m][n];

    return m - lCS_length + n - lCS_length;
}

int main()
{
    std::string str1 = "sea";
    std::string str2 = "eat";
    std::cout<< minSteps(str1,str2)<< std::endl;
return 0;
}
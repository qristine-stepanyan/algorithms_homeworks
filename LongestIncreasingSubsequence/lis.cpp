#include <iostream>
#include <vector>

std::vector<int> longestIncreasingSubsequence(const std::vector<int>& a)
{
    int n = a.size();
    if(n == 0)
    {
        return {};
    }
    std::vector<int> lengths(n,1); 
    std::vector<int> next(n,-1);  
    int maxLength = 0; 
    for(int k = n - 1; k >= 0; --k)
    {
        maxLength = 0; 
        next[k] = -1;
        for(int j = k + 1; j < n; ++j)
        {
            if(a[j] > a[k])
            {
                if(lengths[j] > maxLength)
                { 
                    maxLength = lengths[j];
                    next[k] = j;
                }
            }
        }
        lengths[k] = maxLength + 1;
    }
    int startIndex = 0;
    for(int i = 0; i < n; ++i)
    {
        if(lengths[i] > maxLength)
        {
            maxLength = lengths[i];
            startIndex = i;
        }
    }
    std::vector<int> lis;
    for(int i = startIndex; i != -1; i = next[i])
    {
        lis.push_back(a[i]);
    }
    return lis;
}

int main()
{
    std::vector<int> a = {1,12,2,14,6,4,211,18};
    std::vector<int> lis = longestIncreasingSubsequence(a);
    for(int num : lis)
    {
        std::cout<< num<< " ";
    }
    std::cout<< std::endl;
    return 0;
}

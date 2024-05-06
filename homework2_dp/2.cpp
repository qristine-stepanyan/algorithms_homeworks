#include <iostream>
#include <vector>

const int NEG_INF = -1000000;

void bottomUp(std::vector<int>& price,int n)
{
    std::vector<int> r(n + 1);
    std::vector<int> s(n + 1);

    r[0] = 0;

    for(int j = 1; j <= n; ++j)
    {
        int q = NEG_INF; 
        for(int i = 1; i <= j; ++i)
        {
            if(q < price[i] + r[j - i])
            {
                q = price[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    std::cout << "r array: ";
    for(int i = 0; i <= n; ++i)
    {
        std::cout<< r[i]<< " ";
    }
    std::cout<< std::endl;

    std::cout<< "s array: ";
    for (int i = 0; i <= n; ++i)
    {
        std::cout<< s[i]<< " ";
    }
    std::cout<< std::endl;

    std::cout<< "Optimal split: ";
    while(n > 0)
    {
        std::cout<< s[n]<< " ";
        n -= s[n];
    }
    std::cout<< std::endl;
}

int main()
{
    std::vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24};
    int length = 9;
    bottomUp(price,length);
return 0;
}
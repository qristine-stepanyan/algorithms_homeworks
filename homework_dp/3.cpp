#include <iostream>
#include <vector>

std::vector<std::vector<int>> PascalsTriangle(int numRows)
{
    std::vector<std::vector<int>> arr(numRows);

    for(int i = 0; i < numRows; ++i)
    {
        arr[i].resize(i + 1);
        arr[i][0] = 1; 
        arr[i][i] = 1; 

        for(int j = 1; j < i; ++j)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    return arr;
}

void print(const std::vector<std::vector<int>>& arr)
{
    for(const auto& row : arr)
    {
        for(int num : row)
        {
            std::cout<< num<< " ";
        }
        std::cout<< std::endl;
    }
}

int main()
{
    int numRows;
    std::cin >> numRows;
    std::vector<std::vector<int>> arr = PascalsTriangle(numRows);
    print(arr);
return 0;
}
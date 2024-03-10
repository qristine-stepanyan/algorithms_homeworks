#include <iostream>
#include <vector>

int dfs(int x, int y, int path, const std::vector<std::vector<char>>& grid, int rows, int cols)
{
    int max_path = path;
    std::vector<std::pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    auto isValid = [&](int x,int y)
    {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    };
    
    for(const auto& dir : directions)
    {
        int newX = x + dir.first;
        int newY= y + dir.second;
        if(isValid(newX, newY) && grid[newX][newY] - grid[x][y] == 1)
        {
            max_path = std::max(max_path, dfs(newX, newY, path + 1, grid, rows, cols));
        }
    }
    return max_path;
}

int longest_consecutive_path(const std::vector<std::vector<char>>& grid)
{
    int max_length = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(grid[i][j] == 'A')
            {
                max_length = std::max(max_length, dfs(i, j, 1, grid, rows, cols));
            }
        }
    }
    return max_length;
}

int main()
{
    std::vector<std::vector<char>> grid = {
        {'A', 'B', 'E'},
        {'C', 'F', 'G'},
        {'B', 'D', 'H'},
        {'A', 'B', 'C'}
    };

    std::cout<< longest_consecutive_path(grid) << std::endl;
return 0;
}

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> solutions;
        std::vector<int> queens(n, -1);
        int columns = 0;
        int diagonals1 = 0;
        int diagonals2 = 0;
        backtrack(solutions,queens,n,0,columns,diagonals1,diagonals2);
        return solutions;
    }

private:
    void backtrack(std::vector<std::vector<std::string>> &solutions,std::vector<int> &queens,int n,int row,int columns,int diagonals1,int diagonals2)
    {
        if(row == n)
        {
            solutions.push_back(board(queens,n));
            return;
        }
        for(int col = 0; col < n; ++col)
        {
            int colBit = 1 << col;
            int diag1Bit = 1 << (row - col + n - 1);
            int diag2Bit = 1 << (row + col);
            if (columns & colBit || diagonals1 & diag1Bit || diagonals2 & diag2Bit) 
            {
                continue; 
            }
            queens[row] = col;
            columns |= colBit;
            diagonals1 |= diag1Bit;
            diagonals2 |= diag2Bit;
            backtrack(solutions,queens,n,row + 1,columns,diagonals1,diagonals2);
            queens[row] = -1;
            columns &= ~colBit;
            diagonals1 &= ~diag1Bit;
            diagonals2 &= ~diag2Bit;
        }
    }

    std::vector<std::string> board(std::vector<int> &queens,int n)
    {
        std::vector<std::string> board(n,std::string(n,'.'));
        for(int i = 0; i < n; ++i)
        {
            if(queens[i] != -1)
            {
                board[i][queens[i]] = 'Q';
            }
        }
        return board;
    }
};

int main()
{
    Solution solution;
    int n = 4;
    std::vector<std::vector<std::string>> results = solution.solveNQueens(n);
    for(const auto &solution : results)
    {
        for(const auto &row : solution)
        {
            std::cout<< row<< std::endl;
        }
        std::cout<< std::endl;
    }
return 0;
}
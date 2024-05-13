#include <iostream>
#include <vector>

const int INF = 1e9;

void printOptimalParentheses(std::vector<std::vector<int>>& s,int i,int j)
{
    if(i == j)
    {
        std::cout<< "A"<< i;
    }
    else
    {
        std::cout<< "(";
        printOptimalParentheses(s,i,s[i][j]);
        printOptimalParentheses(s,s[i][j] + 1,j);
        std::cout<< ")";
    }
}

std::pair<std::vector<std::vector<int>>,std::vector<std::vector<int>>> matrixChainOrder(int p[], int n)
{
    std::vector<std::vector<int>> m(n,std::vector<int>(n));
    std::vector<std::vector<int>> s(n,std::vector<int>(n));
    
    for(int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            m[i][j] = INF;
            for(int k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return std::pair<std::vector<std::vector<int>>,std::vector<std::vector<int>>>(m,s);
}

int main(){
    int arr[] = {3, 20, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::pair<std::vector<std::vector<int>>,std::vector<std::vector<int>>> matrices = matrixChainOrder(arr,size);
    std::vector<std::vector<int>> s = matrices.second;
    printOptimalParentheses(s,1,size - 1);
    std::cout<< std::endl;
    std::cout<< matrices.first[1][size - 1]<< std::endl;
    return 0;
}

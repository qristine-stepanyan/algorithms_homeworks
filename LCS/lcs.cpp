#include <iostream>
#include <string>

int lcs3D(std::string x,std::string y,std::string z,int m,int n,int o)
{
    int arr[m + 1][n + 1][o + 1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= o; k++){
                if(i == 0 || j == 0 || k == 0)
                {
                    arr[i][j][k] = 0;
                }
                else if(x[i - 1] == y[j - 1] && x[i - 1] == z[k - 1])
                {
                    arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    arr[i][j][k] = std::max(std::max(arr[i - 1][j][k], arr[i][j - 1][k]), arr[i][j][k - 1]);
                }
            }
        }
    }
    return arr[m][n][o];
}

int main(){
    std::string x = "SAGGT1225";
    std::string y = "S12TxAyB25";
    std::string z = "S12xBA25";
    int m = x.length();
    int n = y.length();
    int o = z.length();
    std::cout<< lcs3D(x,y,z,m,n,o)<< std::endl;
    return 0;
}
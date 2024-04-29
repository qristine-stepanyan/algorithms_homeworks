#include <iostream> 
#include <vector>

int rodCutting(int p[], int n, std::vector<int>& r){
    if(n <= 0){
        return 0;
    }
    if(r[n] != -1){
        return r[n];
    }
    int max_value = 0;
    for(int i = 0; i < n; i++){
        max_value = std::max(max_value, p[i] + rodCutting(p, n - i - 1, r));
    }
    r[n] = max_value;
    return max_value;
}

int main(){
    int n = 4;
    int p[n] = {1, 5, 8, 9};
    std::vector<int> r(n + 1, -1);
    int max_value = rodCutting(p, n, r);
    std::cout << max_value << std::endl;
    return 0;
}

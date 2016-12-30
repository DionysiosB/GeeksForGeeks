#include <iostream>
#include <vector>

//Min cost path when you can move down, right or diagonally
int main(){

    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int> > a(n, std::vector<int>(m, 0));
    for(int p = 0; p < n; p++){for(int q = 0; q < m; q++){std::cin >> a[p][q];}}

    std::vector<std::vector<int> > dp(n, std::vector<int>(m, 0));

    int current(0);
    for(int q = 0; q < m; q++){current += a[0][q]; dp[0][q] = current;}
    current = 0; for(int p = 0; p < n; p++){current += a[p][0]; dp[p][0] = current;}

    for(int p = 1; p < n; p++){
        for(int q = 1; q < m; q++){
            dp[p][q] = a[p][q] + std::min(dp[p - 1][q - 1], std::min(dp[p - 1][q], dp[p][q - 1]));
        }
    }

    std::cout << dp[n - 1][m - 1] << std::endl;

    return 0;
}

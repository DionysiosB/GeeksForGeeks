#include <iostream>
#include <vector>

int main(){

    int m, n; std::cin >> m >> n;
    std::vector<std::vector<long> > dp(m, std::vector<long>(n, 0));
    for(int p = 0; p < m; p++){dp[p][0] = 1;}
    for(int p = 0; p < n; p++){dp[0][p] = 1;}
    for(int p = 1; p < m; p++){
        for(int q = 1; q < n; q++){
            dp[p][q] = dp[p - 1][q] + dp[p][q - 1];
        }
    }

    for(int p = 0; p < m; p++){
        for(int q = 0; q < n; q++){std::cout << dp[p][q] << "\t";}
        std::cout << std::endl;
    }

    std::cout << dp[m - 1][n - 1] << std::endl;



    return 0;
}

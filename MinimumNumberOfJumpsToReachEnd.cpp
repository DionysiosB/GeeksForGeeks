#include <iostream>
#include <vector>

int main(){

    int n; std::cin >> n;
    std::vector<int> jumps(n, 0);
    for(int p = 0; p < n; p++){std::cin >> jumps[p];}

    std::vector<int> dp(n, -1);
    dp[0] = 0;
    for(int p = 0; p < n; p++){
        for(int q = p + 1; q <= p + jumps[p] && q < n; q++){
            if((dp[q] < 0) || (dp[q] > dp[p] + 1)){dp[q] = dp[p] + 1;}
        }
    }

    for(int p = 0; p < n; p++){std::cout << dp[p] << " ";}; std::cout << std::endl;
    std::cout << dp[n - 1] << std::endl;

    return 0;
}

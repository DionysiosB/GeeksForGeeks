#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int nrow, ncol; std::cin >> nrow >> ncol;
    std::vector<std::vector<int> > a(nrow, std::vector<int>(ncol, 0));
    for(int row = 0; row < nrow; row++){
        for(int col = 0; col < ncol; col++){
            std::cin >> a[row][col];
        }
    }

    std::vector<std::vector<int> > dp(nrow, std::vector<int>(ncol, 0));
    for(int col = 0; col < ncol; col++){dp[0][col] = a[0][col];}
    for(int row = 0; row < nrow; row++){dp[row][0] = a[row][0];}

    int maxDim(0);
    for(int row = 1; row < nrow; row++){
        for(int col = 1; col < ncol; col++){
            if(a[row][col] > 0){
                dp[row][col] = 1 + std::min(dp[row - 1][col - 1], std::min(dp[row - 1][col], dp[row][col - 1]));
                maxDim = (dp[row][col] > maxDim) ? dp[row][col] : maxDim;
            }
        }
    }

    std::cout << maxDim << std::endl;

    return 0;
}

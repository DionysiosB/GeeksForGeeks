#include <iostream>
#include <vector>

int main(){

    long n; std::cin >> n;
    std::vector<long> a(n, 0);
    for(long p = 0; p < n; p++){std::cin >> a[p];}

    std::vector<long> sums(n, 0);
    long maxSum(0);
    for(long p = 0; p < n; p++){
        sums[p] = a[p];
        for(long q = 0; q < p; q++){
            if(a[q] >= a[p]){continue;}
            sums[p] = ((sums[p] > (a[p] + sums[q])) ? sums[p] : (a[p] + sums[q]));
            maxSum = (sums[p] > maxSum) ? sums[p] : maxSum;
        }
    }

    for(long p = 0; p < n; p++){std::cout << sums[p] << " ";}; std::cout << std::endl;
    std::cout << maxSum << std::endl;

    return 0;
}

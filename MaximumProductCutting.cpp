#include <iostream>
#include <vector>

int main(){

    int n; std::cin >> n;
    std::vector<long> res(n + 1, 0);
    res[0] = 0; res[1] = 1;
    for(int p = 2; p <= n; p++){
        res[p] = p;
        for(int q = 1; 2 * q <= p; q++){
            long candidate = res[q] * res[p - q];
            if(candidate > res[p]){res[p] = candidate;}
        }
    }

    for(int p = 0; p <= n; p++){std::cout << res[p] << " ";}; std::cout << std::endl;
    std::cout << res[n] << std::endl;

    return 0;
}

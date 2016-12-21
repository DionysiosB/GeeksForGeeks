#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int S, n; std::cin >> S >> n;
    std::vector<int> value(n);
    for(int p = 0; p < n; p++){std::cin >> value[p];}  //assume sorted, if not sort the sequence;
    sort(value.begin(), value.end());

    std::vector<int> numCoins(S + 1, S + 1);
    numCoins[0] = 0;
    for(int p = 1; p <= S; p++){
        for(int q = 0; q < n; q++){
            if(p < value[q]){break;}
            int candidate = numCoins[p - value[q]] + 1;
            if(candidate < numCoins[p]){numCoins[p] = candidate;}
        }
    }

    for(int p = 0; p <= S; p++){std::cout << p << " - " << numCoins[p] << std::endl;}; std::cout << std::endl;
    std::cout << numCoins[S] << std::endl;

    return 0;
}

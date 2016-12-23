#include <iostream>
#include <vector>

int main(){

    long n; std::cin >> n;

    std::vector<long> zeroEnding(n + 1, 0);
    std::vector<long> oneEnding(n + 1, 0);

    zeroEnding[0] = 1; oneEnding[0] = 0;
    for(int p = 1; p <= n; p++){
        zeroEnding[p] = zeroEnding[p - 1] + oneEnding[p - 1];
        oneEnding[p] = zeroEnding[p - 1];
    }

    long ans = zeroEnding[n] + oneEnding[n];
    std::cout << ans << std::endl;

    return 0;
}

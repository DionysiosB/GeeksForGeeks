#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int n; std::cin >> n;
    std::vector<int> a(n);
    for(int p = 0; p < n; p++){std::cin >> a[p];}

    std::vector<int> res(n, 0);
    res[0] = a[0]; 
    if(n >= 1){res[1] = a[1];}
    for(int p = 2; p < n; p++){res[p] = std::max(res[p - 1], res[p - 2] + a[p]);}

    //for(int p = 0; p < n; p++){std::cout << res[p] << " ";}; std::cout << std::endl;
    std::cout << res.back() << std::endl;

    return 0;
}

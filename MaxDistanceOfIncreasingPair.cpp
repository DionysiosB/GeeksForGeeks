#include <iostream>
#include <vector>
#include <algorithm>

// http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

int main(){

    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for(int p = 0; p < n; p++){std::cin >> a[p];}

    std::vector<int> lmin(n, 0);
    lmin[0] = a[0];
    for(int p = 1; p < n; p++){lmin[p] = std::min(lmin[p - 1], a[p]);}

    std::vector<int> rmax(n, 0); rmax[n - 1] = a[n - 1];
    for(int p = n - 2; p >= 0; p--){rmax[p] = std::max(rmax[p + 1], a[p]);}

    int x(0), y(0), furthest(-1);
    while(x < n && y < n){
        if(lmin[x] < rmax[y]){
            furthest = std::max(furthest, y - x);
            ++y;
        }
        else{++x;}
    }

    std::cout << furthest << std::endl;

    return 0;
}

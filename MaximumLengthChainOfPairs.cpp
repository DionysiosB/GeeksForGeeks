#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<std::pair<int, int> > a(n);
    for(int p = 0; p < n; p++){std::cin >> a[p].first >> a[p].second;}
    sort(a.begin(), a.end());

    std::vector<int> v(n, 1);
    for(int p = 1; p < n; p++){
        for(int q = 0; q < p; q++){
            if(a[q].second >= a[p].first){continue;}
            if(v[p] < v[q] + 1){v[p] = v[q] + 1;}
        }
    }

    std::cout << v[n - 1] << std::endl;


    return 0;
}

#include <iostream>
#include <vector>
#include <map>

// http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

int main(){

    int n; std::cin >> n;
    std::vector<int> a(n, 0);
    for(int p = 0; p < n; p++){std::cin >> a[p];}

    std::map<int, std::pair<int, int> > limits;
    limits[0] = std::make_pair(-1, -1);
    int maxLength(-1);
    long sofar(0);
    for(int p = 0; p < n; p++){
        sofar += (2 * a[p] - 1);  //Add 1 if a[p] = 1, subtract otherwise;
        if(limits.count(sofar) > 0){
            limits[sofar].second = p;
            maxLength = std::max(maxLength, limits[sofar].second - limits[sofar].first);
        }
        else{limits[sofar] = std::make_pair(p, -1);}
    }

    std::cout << maxLength << std::endl;

    return 0;
}

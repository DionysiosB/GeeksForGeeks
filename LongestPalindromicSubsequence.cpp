#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::string s; getline(std::cin, s);
    size_t n = s.size();
    std::vector<std::vector<int> > count(n, std::vector<int>(n, 0));
    for(int p = 0; p < n; p++){count[p][p] = 1;}
    for(int p = 0; p < n - 1; p++){count[p][p + 1] = 1 + (s[p] == s[p + 1]);}

    for(int len = 3; len <= n; len++){
        for(int first = 0; first + len <= n; first++){
            int last = first + len - 1;
            if(s[first] == s[last]){count[first][last] = count[first + 1][last - 1] + 2;}
            else{count[first][last] = std::max(count[first + 1][last], count[first][last - 1]);}
        }
    }

    for(int first = 0; first < n; first++){
        for(int last = 0; last < n; last++){std::cout << count[first][last] << "\t";}
        std::cout << std::endl;
    }

    return 0;
}

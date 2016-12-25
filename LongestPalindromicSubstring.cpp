#include <iostream>
#include <vector>

int main(){

    std::string s; getline(std::cin, s);
    size_t n = s.size();

    std::vector<std::vector<bool> > pal(n, std::vector<bool>(n, 0));
    for(int p = 0; p < n; p++){pal[p][p] = 1;}
    for(int p = 0; p < n - 1; p++){pal[p][p + 1] = (s[p] == s[p + 1]);}

    int maxLength(1);
    std::pair<int, int> longest = std::make_pair(0, 0);
    for(int len = 3; len <= n; len++){
        for(int start = 0; start + len <= n; start++){
            int finish = start + len - 1;
            pal[start][finish] = pal[start + 1][finish - 1] && (s[start] == s[finish]);
            if(pal[start][finish] && len > maxLength){
                maxLength = len;
                longest = std::make_pair(start, len);
            }
        }
    }


    for(int p = 0; p < n; p++){
        for(int q = 0; q < n; q++){std::cout << pal[p][q] << "\t";}
        std::cout << std::endl;
    }

    std::cout << s.substr(longest.first, longest.second) << std::endl;

    return 0;
}

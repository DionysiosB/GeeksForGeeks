#include <iostream>
#include <vector>

int main(){

    long S, n; std::cin >> S >> n;
    std::vector<long> value(n, 0);
    for(long p = 0; p < n; p++){std::cin >> value[p];}

    std::vector<std::vector<long> > ways(n, std::vector<long>(S + 1, 0));
    for(long row = 0; row < n; row++){ways[row][0] = 1;}
    for(long col = 0; col <= S; col++){ways[0][col] = 1;}

    for(long row = 1; row < n; row++){
        for(long col = 1; col <= S; col++){
            ways[row][col] = ways[row - 1][col] + ((col >= value[row]) ? (ways[row][col - value[row]]) : 0);
        }
    }
    
    for(long row = 0; row < n; row++){
        for(long col = 0; col <= S; col++){std::cout << ways[row][col] << "\t";}
        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

int main(){

    int n; std::cin >> n;
    std::vector<std::pair<long, long> > mat(n);
    for(int p = 0; p < n; p++){std::cin >> mat[p].first >> mat[p].second;}

    std::vector<std::vector<long> > count(n, std::vector<long>(n, 0));

    for(long len = 2; len <= n; len++){
        for(long start = 0; start + len <= n; start++){
            long finish = start + len - 1;

            long candidateA = mat[start].first * mat[start].second * mat[finish].second + count[start + 1][finish]; 
            long candidateB = count[start][finish - 1] + mat[start].first * mat[finish].first * mat[finish].second;
            count[start][finish] = std::min(candidateA, candidateB);
        }
    }

    for(long p = 0; p < n; p++){
        for(long q = 0; q < n; q++){std::cout << count[p][q] << "\t";}
        std::cout << std::endl;
    }

    std::cout << count[0][n - 1] << std::endl;

    return 0;
}

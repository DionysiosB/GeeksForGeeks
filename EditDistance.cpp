#include <iostream>
#include <vector>

int main(){

    std::string s; getline(std::cin, s);
    std::string t; getline(std::cin, t);

    int nrow = s.size() + 1;
    int ncol = t.size() + 1;

    std::vector<std::vector<int> > count(nrow, std::vector<int>(ncol, 0));

    for(int p = 0; p < ncol; p++){count[0][p] = p;}
    for(int p = 0; p < nrow; p++){count[p][0] = p;}

    for(int row = 1; row < nrow; row++){
        for(int col = 1; col < ncol; col++){
            count[row][col]= std::min(count[row - 1][col - 1], std::min(count[row - 1][col], count[row][col - 1])) + (s[row - 1] != t[col - 1]);
        }
    }

    for(int row = 0; row < nrow; row++){
        for(int col = 0; col < ncol; col++){std::cout << count[row][col] << "\t";}
        std::cout << std::endl;
    }

    std::cout << count[s.size()][t.size()] << std::endl;

    return 0;
}

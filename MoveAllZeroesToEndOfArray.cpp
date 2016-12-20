#include <iostream>

int main(){

    int t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        int count(0);
        while(n--){
            int x; std::cin >> x;
            if(x != 0){std::cout << x << " ";}
            else{++count;}
        }

        while(count--){std::cout << "0 ";}
        std::cout << std::endl;
    }

    return 0;
}

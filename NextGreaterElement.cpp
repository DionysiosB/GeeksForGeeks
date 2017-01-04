#include <iostream>
#include <vector>

// http://www.geeksforgeeks.org/next-greater-element/

int main(){

    int n; std::cin >> n;
    if(n <= 0){return 0;}
    std::vector<int> a(n, 0);
    for(int p = 0; p < n; p++){std::cin >> a[p];}

    std::vector<std::pair<int, int> > nextGreater(n, std::pair<int, int>(-1, -1));   //Vector with the next greater element (pos, number);
    std::vector<std::pair<int, int> > stack;

    for(int p = 1; p < n; p++){
        if(stack.size() == 0 || a[p] <= stack.back().second){stack.push_back(std::make_pair(p, a[p]));}
        else{
            while(stack.size() > 0 && a[p] > stack.back().second){
                int prevPos = stack.back().first;
                nextGreater[prevPos] = std::make_pair(p, a[p]);
                stack.pop_back();
            }
        }
    }

    for(int p = 0; p < n; p++){std::cout << nextGreater[p].second << " ";}; std::cout << std::endl;

    return 0;
}

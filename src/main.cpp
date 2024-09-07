#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <random>
#include "../include/Tableaux.hpp"


std::vector<int> generatePermutation(int n) {
    std::vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }
    std::random_device rd;
    std::mt19937 g(rd()); 
    std::shuffle(permutation.begin(), permutation.end(), g);

    return permutation;
}

int main() {

    std::vector<int> permutation = generatePermutation(5);

    for (int x : permutation) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    Tableaux t = Tableaux();

    t.insertion(permutation);

    std::cout << t;



    return 0;
}
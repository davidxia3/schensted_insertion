#include <vector>
#include <utility>
#include <iostream>
#include "../include/Tableaux.hpp"

int main() {

    std::vector<int> permutation = {3,2, 4,1};

    Tableaux t = Tableaux();

    t.insertion(permutation);

    std::cout << t;



    return 0;
}
#include <vector>
#include <utility>
#include <iostream>
#include "../include/Tableaux.hpp"

int main() {

    std::vector<int> permutation = {2,1,4,5,3};

    Tableaux t = Tableaux();

    t.insertion(permutation);

    std::cout << t;



    return 0;
}
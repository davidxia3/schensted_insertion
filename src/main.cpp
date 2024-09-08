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

void plotVector(const std::vector<int>& data, int start, int stop, int step) {
    int max_val = *std::max_element(data.begin(), data.end());
    
    int scale = 50;


    for (int i = 0; i < data.size(); ++i) {
        std::cout << "[" << start + i * step << "] ";
        int bar_length = data[i] * scale / max_val;
        for (int j = 0; j < bar_length; ++j) {
            std::cout << "#";
        }
        std::cout << " (" << data[i] << ")\n";
    }
}

int main() {

    // std::vector<int> permutation = generatePermutation(5);

    // for (int x : permutation) {
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;

    // Tableaux t = Tableaux();

    // std::cout << t.determineBoring(permutation) << std::endl;



    int start = 1;
    int stop = 50;
    int step = 1;


    std::vector<int> counts;
    for (int i = start; i < stop; i=i+step) {
        std::cout << i << std::endl;
        int count = 0;
        for (int j = 0; j < 100;j++) {
            std::vector<int> permutation = generatePermutation(i);
            Tableaux t = Tableaux();

            if (t.determineBoring(permutation)) {
                count = count + 1;
            }
        }
        counts.push_back(count);
    }

    plotVector(counts, start, stop, step);



    return 0;
}
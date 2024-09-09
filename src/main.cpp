#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <random>
#include <map>
#include "../include/Tableaux.hpp"


void printMap(const std::map<std::vector<int>, int>& map) {
    for (const auto& pair : map) {
        std::cout << "{ ";
        for (const auto& elem : pair.first) {
            std::cout << elem << " ";
        }
        std::cout << "} : " << pair.second << std::endl;
    }
}

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

void plotVector(const std::vector<int>& data, int start, int step) {
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

bool checkSequences(std::vector<int> permutation, std::vector<int> sequences) {
    int sequence = 1;
    int sequencesIndex = 0;

    for (int i = 1; i < permutation.size(); i++) {
        if (permutation[i] > permutation[i - 1]) {
            sequence++;
        } else {
            if (sequencesIndex >= sequences.size() || sequences[sequencesIndex] != sequence) {
                return false;
            }
            sequencesIndex++;
            sequence = 1;
        }
    }

    if (sequencesIndex >= sequences.size() || sequences[sequencesIndex] != sequence) {
        return false;
    }

    return sequencesIndex == sequences.size() - 1;
}

std::vector<int> getSequences(std::vector<int>& permutation) {
    std::vector<int> sequences;
    int sequenceLength = 1;

    for (int i = 1; i < permutation.size(); i++) {
        if (permutation[i] > permutation[i - 1]) {
            sequenceLength++;
        } else {
            sequences.push_back(sequenceLength);
            sequenceLength = 1;
        }
    }

    sequences.push_back(sequenceLength);

    return sequences;
}

int main() {

    // std::vector<int> permutation = generatePermutation(6);

    // for (int x : permutation) {
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;

    // Tableaux t = Tableaux();

    // t.insertion(permutation);

    // std::cout << t.p.interesting << std::endl;


    // int start = 1;
    // int stop = 10;
    // int step = 1;


    // std::vector<int> counts;
    // for (int i = start; i < stop; i=i+step) {
    //     std::cout << i << std::endl;
    //     int count = 0;
    //     for (int j = 0; j < 100;j++) {
    //         std::vector<int> permutation = generatePermutation(i);
    //         Tableaux t = Tableaux();

    //         t.insertion(permutation);
    //         if (t.p.interesting) {
    //             count = count + 1;
    //         }
    //     }
    //     counts.push_back(count);
    // }

    // plotVector(counts, start, step);



    std::vector<int> elements;
    for (int j = 0; j < 5; j++) {
        elements.push_back(j+1);
    }

    std::map<std::vector<int>, int> totals;
    std::map<std::vector<int>, int> interestings;

    do {
        Tableaux t = Tableaux();

        std::vector<int> sequences = getSequences(elements);

        if (totals.find(sequences) == totals.end()) {
            totals[sequences] = 1;
        } else {
            totals[sequences] = totals[sequences] + 1;
        }

        t.insertion(elements);
        if (interestings.find(sequences) == interestings.end()) {
            interestings[sequences] = 0;
        }

        if (t.p.interesting) {
            interestings[sequences] = interestings[sequences] + 1;
        }
        
    } while (std::next_permutation(elements.begin(), elements.end()));


    printMap(totals);
    std::cout << std::endl;
    printMap(interestings);




    return 0;
}
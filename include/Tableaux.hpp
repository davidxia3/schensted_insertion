#ifndef TABLEAUX_HPP
#define TABLEAUX_HPP
#include "InsertionTableau.hpp"
#include "RecordingTableau.hpp"

class Tableaux {
    public: 
        Tableaux();

        void insertion(std::vector<int> permutation);

        bool determineBoring(std::vector<int> permutation);

        InsertionTableau p;
        RecordingTableau q;

        friend std::ostream& operator<<(std::ostream& os, const Tableaux& tableaux);
};

#endif
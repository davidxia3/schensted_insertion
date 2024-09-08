#ifndef INSERTIONTABLEAU_HPP
#define INSERTIONTABLEAU_HPP
#include <vector>
#include <utility>
#include <iostream>

class InsertionTableau {
    public: 
        InsertionTableau();

        std::pair<int, int> insert(int x);

        bool determineBoring(std::vector<int> permutation);

        friend std::ostream& operator<<(std::ostream& os, const InsertionTableau& it);

        std::vector<std::vector<int> > t;

        bool boring = false;

        std::vector<int> list;

};

#endif
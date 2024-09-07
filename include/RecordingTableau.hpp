#ifndef RECORDINGTABLEAU_HPP
#define RECORDINGTABLEAU_HPP
#include <vector>
#include <utility>
#include <iostream>

class RecordingTableau {
    public: 
        RecordingTableau();

        void insert(int x, std::pair<int, int> s);

        friend std::ostream& operator<<(std::ostream& os, const RecordingTableau& rt);

        std::vector<std::vector<int> > t;

};

#endif
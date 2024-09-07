#include "../include/InsertionTableau.hpp"

InsertionTableau::InsertionTableau() {
    
}

std::pair<int, int> InsertionTableau::insert(int x) {
    int i = 0;
    while (true) {
        if (t.size() <= i) {
            t.push_back(std::vector<int>(1, x));
            return std::make_pair(i,0);
        }

        int j = t[i].size();

        while (j > 0 && x < t[i][j-1]) {
            j = j - 1;
        }

        if (j == t[i].size()) {
            t[i].push_back(x);
            return std::make_pair(i, j);
        }

        int temp = t[i][j];
        t[i][j] = x;
        x = temp;

        i = i + 1;
    }
}

std::ostream& operator<<(std::ostream& os, const InsertionTableau& it) {
    for (int i = 0; i < it.t.size(); i++) {
        for (int j = 0; j < it.t[i].size(); j++) {
            os << it.t[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
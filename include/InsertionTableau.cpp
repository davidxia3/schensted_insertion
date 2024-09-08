#include "../include/InsertionTableau.hpp"

InsertionTableau::InsertionTableau() {
    boring = false;
    list = std::vector<int>();
}

std::pair<int, int> InsertionTableau::insert(int x) {
    int i = 0;

    int initialColumn = -1;
    
    while (true) {
        if (t.size() <= i) {
            t.push_back(std::vector<int>(1, x));
            if (initialColumn == 0) {
                boring = true;
            }
            return std::make_pair(i,0);
        }

        int j = t[i].size();

        while (j > 0 && x < t[i][j-1]) {
            j = j - 1;
        }

        if (j == t[i].size()) {
            t[i].push_back(x);
            if (initialColumn == t[i].size()-1) {
                boring = true;
            }
            return std::make_pair(i, j);
        }

        if (initialColumn == -1) {
            initialColumn = j;
        } else if (initialColumn == j) {
            boring = true;
        } else {
            initialColumn = -2;
        }

        int temp = t[i][j];
        t[i][j] = x;
        x = temp;

        i = i + 1;
    }
}

bool InsertionTableau::determineBoring(std::vector<int> permutation) {
    for (int x : permutation) {
        insert(x);
        if (boring) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const InsertionTableau& it) {
    os << "Has boring: ";
    os << (it.boring ? "true" : "false");
    os << "\n";
    for (int i = 0; i < it.t.size(); i++) {
        for (int j = 0; j < it.t[i].size(); j++) {
            os << it.t[i][j] << " ";
        }
        os << "\n";
    }

    os << "List of boring: ";
    for (int i = 0; i < it.list.size(); i++) {
        os << it.list[i] << " ";
    }
    os << "\n";
    
    return os;
}
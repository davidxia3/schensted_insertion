#include "../include/InsertionTableau.hpp"

InsertionTableau::InsertionTableau() {
    boring = false;
    list = std::vector<int>();
}

std::pair<int, int> InsertionTableau::insert(int x) {
    int i = 0;
    int previous = -1;
    while (true) {
        if (t.size() <= i) {
            t.push_back(std::vector<int>(1, x));
            if (previous != -1 && previous == 0) {
                boring = true;
                list.push_back(x);
            } 
            previous = 0;
            return std::make_pair(i,0);
        }

        int j = t[i].size();

        while (j > 0 && x < t[i][j-1]) {
            j = j - 1;
        }

        if (j == t[i].size()) {
            t[i].push_back(x);
            if (previous != -1 && previous == t[i].size() - 1) {
                boring = true;
                list.push_back(x);
            } 
            previous = t[i].size() - 1;
            return std::make_pair(i, j);
        }

        if (previous != -1 && previous == j) {
            boring = true;
            list.push_back(x);
        }

        int temp = t[i][j];
        t[i][j] = x;
        x = temp;
        previous = j;

        i = i + 1;
    }
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
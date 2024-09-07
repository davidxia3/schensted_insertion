#include "../include/RecordingTableau.hpp"

RecordingTableau::RecordingTableau() {
    
}

void RecordingTableau::insert(int x, std::pair<int, int> s) {
    if (t.size() <= s.first) {
        t.push_back(std::vector<int>(1, x));
        return;
    }
    if (t[s.first].size() <= s.second) {
        t[s.first].push_back(x);
        return;
    }
    t[s.first][s.second] = x;
}

std::ostream& operator<<(std::ostream& os, const RecordingTableau& rt) {
    for (int i = 0; i < rt.t.size(); i++) {
        for (int j = 0; j < rt.t[i].size(); j++) {
            os << rt.t[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
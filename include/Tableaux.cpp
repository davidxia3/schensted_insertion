#include "../include/Tableaux.hpp"

Tableaux::Tableaux() {
    p = InsertionTableau();
    q = RecordingTableau();
}

void Tableaux::insertion(std::vector<int> permutation) {
    for (int i = 0; i < permutation.size(); i++) {
        std::pair<int, int> s = p.insert(permutation[i]);
        q.insert(i + 1, s);
    }
}

bool Tableaux::determineBoring(std::vector<int> permutation) {
    return p.determineBoring(permutation);
}

std::ostream& operator<<(std::ostream& os, const Tableaux& tableaux) {
    os << "Insertion Tableau (P):\n";
    os << tableaux.p;
    os << "Recording Tableau (Q):\n";
    os << tableaux.q; 
    return os;
}


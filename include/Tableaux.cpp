#include "../include/Tableaux.hpp"

Tableaux::Tableaux() {
    p = InsertionTableau();
    q = RecordingTableau();
}

void Tableaux::insertion(std::vector<int> permutation) {
    std::cout << *this << std::endl;
    for (int i = 0; i < permutation.size(); i++) {
        std::pair<int, int> s = p.insert(permutation[i]);
        std::cout << s.first << " " << s.second <<std::endl;
        q.insert(i + 1, s);
        std::cout << *this << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Tableaux& tableaux) {
    os << "Insertion Tableau (P):\n";
    os << tableaux.p;
    os << "Recording Tableau (Q):\n";
    os << tableaux.q; 
    return os;
}


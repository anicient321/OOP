#include "3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

namespace student_records {
    Student::Student(const std::string& ime, const std::string& prezime, int bodovi)
        : ime(ime), prezime(prezime), bodovi(bodovi) {}
    
    int bodovi_u_ocjenu(int bodovi) {
        if (bodovi < 40) return 1;
        if (bodovi < 55) return 2;
        if (bodovi < 70) return 3;
        if (bodovi < 85) return 4;
        return 5;
    }
}

int main() {
    using namespace student_records;
    
    std::ifstream file("studenti.txt");
    std::vector<Student> studenti;
    std::string ime, prezime;
    int bodovi;
    while (file >> ime >> prezime >> bodovi) {
        studenti.push_back(Student(ime, prezime, bodovi));
    }
    
    studenti.erase(std::remove_if(studenti.begin(), studenti.end(),
        [](const Student& s) { return s.bodovi < 40; }), studenti.end());
    
    std::transform(studenti.begin(), studenti.end(), studenti.begin(),
        [](Student s) { 
            s.bodovi = bodovi_u_ocjenu(s.bodovi);
            return s;
        });
    
    double prosjek = std::accumulate(studenti.begin(), studenti.end(), 0.0,
        [](double acc, const Student& s) { return acc + s.bodovi; }) / 
        static_cast<double>(studenti.size());
    
    std::sort(studenti.begin(), studenti.end(),
        [](const Student& a, const Student& b) { return a.prezime < b.prezime; });
    
    std::cout << "izvjestaj:" << std::endl;
    for (const auto& s : studenti) {
        std::cout << s.prezime << " " << s.ime << " - ocjena: " << s.bodovi << std::endl;
    }
    std::cout << "prosjek ocjena: " << prosjek << std::endl;
    
    return 0;
}

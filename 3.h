#ifndef 3_H
#define 3_H

#include <string>

namespace student_records {
    class Student {
    public:
        std::string ime;
        std::string prezime;
        int bodovi;
        
        Student(const std::string& ime, const std::string& prezime, int bodovi);
    };
    
    int bodovi_u_ocjenu(int bodovi);
}

#endif

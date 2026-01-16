#include "Course.h"

Course::Course() : name(""), code(""), ects(5) {}

Course::Course(const std::string& name, const std::string& code, int ects)
    : name(name), code(code), ects(ects) {}

std::ostream& operator<<(std::ostream& os, const Course& c) {
    os << c.name << " (" << c.code << ") - " << c.ects << " ects";
    return os;
}

std::istream& operator>>(std::istream& is, Course& c) {
    std::cout << "ime: ";
    std::getline(is, c.name);
    std::cout << "sifra: ";
    std::getline(is, c.code);
    std::cout << "ects: ";
    is >> c.ects;
    is.ignore();
    return is;
}

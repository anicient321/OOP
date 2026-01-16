#include "Student.h"
#include "Course.h"
#include "UniversityConstants.h"

int Student::total_students = 0;

Student::Student(int id, const std::string& name, const std::string& study_program, int year)
    : id(id), name(name), study_program(study_program), year(year), 
      enrolled_courses(nullptr), enrolled_count(0), 
      completed_courses(nullptr), completed_count(0) {
    total_students++;
}

Student::Student(const Student& other)
    : id(other.id), name(other.name), study_program(other.study_program), year(other.year),
      enrolled_count(other.enrolled_count), completed_count(other.completed_count) {
    if (enrolled_count > 0) {
        enrolled_courses = new Course[enrolled_count];
        for (size_t i = 0; i < enrolled_count; ++i) {
            enrolled_courses[i] = other.enrolled_courses[i];
        }
    } else {
        enrolled_courses = nullptr;
    }
    
    if (completed_count > 0) {
        completed_courses = new Course[completed_count];
        for (size_t i = 0; i < completed_count; ++i) {
            completed_courses[i] = other.completed_courses[i];
        }
    } else {
        completed_courses = nullptr;
    }
    
    total_students++;
}

Student::Student(Student&& other)
    : id(other.id), name(std::move(other.name)), study_program(std::move(other.study_program)), 
      year(other.year), enrolled_courses(other.enrolled_courses), enrolled_count(other.enrolled_count),
      completed_courses(other.completed_courses), completed_count(other.completed_count) {
    other.enrolled_courses = nullptr;
    other.enrolled_count = 0;
    other.completed_courses = nullptr;
    other.completed_count = 0;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] enrolled_courses;
        delete[] completed_courses;
        
        id = other.id;
        name = other.name;
        study_program = other.study_program;
        year = other.year;
        enrolled_count = other.enrolled_count;
        completed_count = other.completed_count;
        
        if (enrolled_count > 0) {
            enrolled_courses = new Course[enrolled_count];
            for (size_t i = 0; i < enrolled_count; ++i) {
                enrolled_courses[i] = other.enrolled_courses[i];
            }
        } else {
            enrolled_courses = nullptr;
        }
        
        if (completed_count > 0) {
            completed_courses = new Course[completed_count];
            for (size_t i = 0; i < completed_count; ++i) {
                completed_courses[i] = other.completed_courses[i];
            }
        } else {
            completed_courses = nullptr;
        }
    }
    return *this;
}

Student& Student::operator=(Student&& other) {
    if (this != &other) {
        delete[] enrolled_courses;
        delete[] completed_courses;
        
        id = other.id;
        name = std::move(other.name);
        study_program = std::move(other.study_program);
        year = other.year;
        enrolled_courses = other.enrolled_courses;
        enrolled_count = other.enrolled_count;
        completed_courses = other.completed_courses;
        completed_count = other.completed_count;
        
        other.enrolled_courses = nullptr;
        other.enrolled_count = 0;
        other.completed_courses = nullptr;
        other.completed_count = 0;
    }
    return *this;
}

Student::~Student() {
    delete[] enrolled_courses;
    delete[] completed_courses;
    total_students--;
}

int Student::get_total_students() {
    return total_students;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << "id: " << s.id << ", ime: " << s.name << ", smjer: " << s.study_program << ", godina: " << s.year;
    return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
    std::cout << "id: ";
    is >> s.id;
    is.ignore();
    std::cout << "ime: ";
    std::getline(is, s.name);
    std::cout << "smjer: ";
    std::getline(is, s.study_program);
    std::cout << "godina: ";
    is >> s.year;
    return is;
}

Student& Student::operator+=(const Course& course) {
    Course* temp = new Course[enrolled_count + 1];
    for (size_t i = 0; i < enrolled_count; ++i) {
        temp[i] = enrolled_courses[i];
    }
    temp[enrolled_count] = course;
    delete[] enrolled_courses;
    enrolled_courses = temp;
    enrolled_count++;
    return *this;
}

Student& Student::operator++() {
    int total = 0;
    for (size_t i = 0; i < completed_count; ++i) {
        total += 5;
    }
    if (total >= UniversityConstants::REQUIRED_ECTS_PER_YEAR) {
        year++;
    }
    return *this;
}

Student Student::operator++(int) {
    Student temp(*this);
    ++(*this);
    return temp;
}

#include "Student.h"
#include "Course.h"
#include "UniversityConstants.h"
#include "StudentOffice.h"
#include <vector>

int main() {
    std::vector<Student> students;
    students.push_back(Student(1, "ana", "racunarstvo", 1));
    students.push_back(Student(2, "ivan", "matematika", 2));
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << students[i] << std::endl;
    }
    
    std::cout << "ukupno: " << Student::get_total_students() << std::endl;
    
    UniversityConstants::print_university_rules();
    
    Course c1("programiranje", "cs1", 5);//kolegiji itd.
    Course c2("matematika", "mat1", 5);
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    
    std::cout << "\nrule of five ===" << std::endl;
    Student s1(3, "marko", "racnuarstvo", 1);
    Student s2(s1);
    Student s3(std::move(s2));
    std::cout << s1 << std::endl;
    std::cout << s3 << std::endl;
    
    std::cout << "\n=== 6. operatori ===" << std::endl;
    Student s4(4, "petra", "racunarstvo", 1);
    s4 += c1;
    s4 += c2;
    std::cout << "upisano kolegija: " << s4.enrolled_count << std::endl;
    
    std::cout << "\n=== 7. studentoffice ===" << std::endl;
    StudentOffice office;
    
    Course c3("fizika", "fiz1", 5);
    Course c4("baze", "bp1", 5);
    Course c5("algoritmi", "alg1", 5);
    Course c6("web", "web1", 5);
    Course c7("os", "os1", 5);
    Course c8("mreze", "rm1", 5);
    Course c9("digitalnisustavi", "ds1", 5);
    
    office.enroll_student(s4, c3);
    office.enroll_student(s4, c4);
    office.enroll_student(s4, c5);
    office.enroll_student(s4, c6);
    office.enroll_student(s4, c7);
    office.enroll_student(s4, c8);
    office.enroll_student(s4, c9);
    
    std::cout << "ukupno upisano: " << s4.enrolled_count << std::endl;
    
    office.process_exam_results(s4, "CS101");
    office.process_exam_results(s4, "MA101");
    office.process_exam_results(s4, "PH101");
    office.process_exam_results(s4, "CS102");
    office.process_exam_results(s4, "CS103");
    office.process_exam_results(s4, "CS104");
    office.process_exam_results(s4, "CS105");
    office.process_exam_results(s4, "CS106");
    office.process_exam_results(s4, "CS107");
    
    std::cout << "polozeno: " << s4.completed_count << std::endl;
    std::cout << "prije ++: " << s4 << std::endl;
    ++s4;
    std::cout << "nakon ++: " << s4 << std::endl;
    
    office.moveStudent(s4, "informatika");
    std::cout << "nakon move: " << s4 << std::endl;
    
    std::vector<Student> svi;
    svi.push_back(Student(5, "luka", "racunarstvo", 1));
    svi.push_back(Student(6, "maja", "matematika", 1));
    
    StudentOffice office2;
    Course k1("kolegij1", "K1", 5);
    Course k2("kolegij2", "K2", 5);
    Course k3("kolegij3", "K3", 5);
    Course k4("kolegij4", "K4", 5);
    Course k5("kolegij5", "K5", 5);
    Course k6("kolegij6", "K6", 5);
    Course k7("kolegij7", "K7", 5);
    Course k8("kolegij8", "K8", 5);
    Course k9("kolegij9", "K9", 5);
    
    office2.enroll_student(svi[0], k1);
    office2.enroll_student(svi[0], k2);
    office2.enroll_student(svi[0], k3);
    office2.enroll_student(svi[0], k4);
    office2.enroll_student(svi[0], k5);
    office2.enroll_student(svi[0], k6);
    office2.enroll_student(svi[0], k7);
    office2.enroll_student(svi[0], k8);
    office2.enroll_student(svi[0], k9);
    
    office2.process_exam_results(svi[0], "K1");
    office2.process_exam_results(svi[0], "K2");
    office2.process_exam_results(svi[0], "K3");
    office2.process_exam_results(svi[0], "K4");
    office2.process_exam_results(svi[0], "K5");
    office2.process_exam_results(svi[0], "K6");
    office2.process_exam_results(svi[0], "K7");
    office2.process_exam_results(svi[0], "K8");
    office2.process_exam_results(svi[0], "K9");
    
    std::cout << "\nprijе update_student_years:" << std::endl;
    for (size_t i = 0; i < svi.size(); ++i) {
        std::cout << svi[i] << std::endl;
    }
    
    office2.update_student_years(svi);
    
    std::cout << "\nnakon update_student_years:" << std::endl;
    for (size_t i = 0; i < svi.size(); ++i) {
        std::cout << svi[i] << std::endl;
    }
    
    return 0;
}

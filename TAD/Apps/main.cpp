#include <iostream>
#include "Students.h"

using namespace std;

int main() {
    Student student;  // Criando um objeto da classe Student
    student.setStudent("Thiago Alexandre Guerra", 1052001);  // Correto
    student.setScores();
    student.ReadingStudentsScores();
    student.propertiesOfVectorSudentsGrades();

    return 0;
}

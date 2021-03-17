#include "students.h"

int main(){

    Students** students = init();    

    get_student(students);
    student_average(students);

    printf("Highest average by students: %.2f.\n", highest_student_average(students));
    printf("Highest average by subjects: %.2f.\n", highest_subject_average(students));

/*     print_students(students);
 */
    return 0;
}
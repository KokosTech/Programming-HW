#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENTS 2
#define SUBJECTS 3
#define GRADES 1 // number of months in 
                     // 1/2 of a school year

typedef struct{
    struct names{
        char* first;
        char* last;
    } name;
    struct grades{
        int subjects[SUBJECTS][GRADES];
        float average;
    } grade;
} Students;

enum Subjects {MATH, BGL, PROGRAMMING};

// Core Functions 

char *get_string(){    
    int logSize = 0, phySize = 1;  
    char *res, c;

    res = (char *)malloc(sizeof(char));
    c = getchar();

    while(c != '\n'){
        if(logSize == phySize){
            phySize *= 2;
            res = (char *)realloc(res, sizeof(char) * phySize);
        }
        res[logSize++] = c;
        c = getchar();
    }

    res = (char *)realloc(res, sizeof(char *) * (logSize + 1));
    res[logSize] = '\0';
    return res;
}

// Starting Functions

Students** init(){
    Students **student = (Students**) malloc(STUDENTS * sizeof(Students*));

    // Allocating for every student
    for (int i = 0; i < STUDENTS; i++) {
        student[i] = (Students*) malloc(sizeof(Students));

        // Names

        student[i]->name.first = (char*) malloc(sizeof(char));
        student[i]->name.first = (char*) malloc(sizeof(char));

        // Grades

        for(int j = 0; j < SUBJECTS; ++j)
            for(int k = 0; k < GRADES; ++k)         // To @malkoto1 (Radoslav Asparuhov): 
                student[i]->grade.subjects[j][k] = 0;   // ... and you thought we'll never use triple for
        
        student[i]->grade.average = 0;
    }

    return student;
}

// To be optimized in the furure - instead of 2 FORs, only 1

void get_names(Students** students){
    for(int i = 0; i < STUDENTS; ++i){
        printf("First name: ");
            students[i]->name.first = get_string();
        printf("Last name: "); 
            students[i]->name.last = get_string();            
    }
}

void get_grades(Students** students){
    for(int i = 0; i < STUDENTS; ++i){
        printf("Entering %s's grades:\n\n", students[i]->name.first);

        // To be optimized (by outsourcing to a function) in the future

        printf("Enter %d math grades: ", GRADES);
        for(int j = 0; j < GRADES; ++j)
            scanf("%d", &students[i]->grade.subjects[MATH][j]);

        printf("Enter %d BGL grades: ", GRADES);
        for(int j = 0; j < GRADES; ++j)
            scanf("%d", &students[i]->grade.subjects[BGL][j]);

        printf("Enter %d programming grades: ", GRADES);
        for(int j = 0; j < GRADES; ++j)
            scanf("%d", &students[i]->grade.subjects[PROGRAMMING][j]);
    }
}

void get_student(Students** students){
    printf("Thank you for purchasing %d students™!\n", STUDENTS);
    printf("Please enter it's credentials:\n\n");

    printf("Names:\n");
    get_names(students);

    printf("\nGrades:\n");
    get_grades(students);
}

// Calculation Functions

void student_average(Students** students){
    int sum = 0, NUM = SUBJECTS * GRADES;

    for(int i = 0; i < STUDENTS; ++i){
        for(int j = 0; j < SUBJECTS; ++j)
            for(int k = 0; k < GRADES; ++k)
                sum += students[i]->grade.subjects[j][k]; 
        
        students[i]->grade.average = (float) sum / NUM; 
        sum = 0;
    }
    
}

float* subject_average(Students** students){
    static float average[SUBJECTS]; 
    float sum[SUBJECTS];

    // Init

    for(int i = 0; i < SUBJECTS; ++i){
        average[i] = 0;
        sum[i] = 0;
    }

    for(int i = 0; i < STUDENTS; ++i){
        for(int j = 0; j < SUBJECTS; ++j)
            for(int k = 0; k < GRADES; ++k)
                sum[j] += students[i]->grade.subjects[j][k]; 
    }

    // Calculate
    
    for(int i = 0; i < SUBJECTS; ++i)
        average[i] = sum[i] / STUDENTS;

    return average;
}

// Analytics

float highest_student_average(Students** students){
    float max; 

    for(int i = 0; i < STUDENTS; ++i)
        if(students[i]->grade.average > max)
            max = students[i]->grade.average;
    
    return max;
}

float highest_subject_average(Students** students){
    float* average, max;
    average = subject_average(students);

    for(int i = 0; i < SUBJECTS; ++i)
        if(*(average + i) > max)
            max = *(average + i);

    return max;
}
// Console Functions

void print_students(Students** students){

    for(int i = 0; i < STUDENTS; ++i){
        printf("\n\nFirst Name: %s\n", students[i]->name.first);
        printf("Last Name: %s\n\n", students[i]->name.last);

        printf("Grades:\n");
        printf("Math: ");
            for(int j = 0; j < GRADES; ++j)
                printf("%d", students[i]->grade.subjects[MATH][j]);
        putchar('\n');
        
        printf("BGL: ");
            for(int j = 0; j < GRADES; ++j)
                printf("%d", students[i]->grade.subjects[BGL][j]);
        putchar('\n');

        printf("Programming: ");
            for(int j = 0; j < GRADES; ++j)
                printf("%d", students[i]->grade.subjects[PROGRAMMING][j]);
        putchar('\n');
    }
}
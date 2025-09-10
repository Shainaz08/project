#include <stdio.h>
#include <string.h>

#define MAX 50  // Maximum students

// Structure for Student
struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;  // number of students

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

void addStudent() {
    if (count == MAX) {
        printf("Student list full!\n");
        return;
    }
    printf("Enter Roll No: ");
    scanf("%d", &students[count].rollNo);
    printf("Enter Name: ");
    scanf("%s", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n",
               students[i].rollNo, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int rollNo;
    printf("Enter Roll No to search: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Student Found: Roll No=%d, Name=%s, Marks=%.2f\n",
                   students[i].rollNo, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent() {
    int rollNo;
    printf("Enter Roll No to update: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student updated successfully!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int rollNo;
    printf("Enter Roll No to delete: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found.\n");
}
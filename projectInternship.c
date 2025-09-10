#include <stdio.h>
#include <string.h>

#define MAX 50  // Maximum employees

// Structure for Employee
struct Employee {
    int id;
    char name[50];
    float salary;
};

struct Employee employees[MAX];
int count = 0;  // number of employees

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();

int main() {
    int choice;
    do {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

void addEmployee() {
    if (count == MAX) {
        printf("Employee list full!\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &employees[count].id);
    printf("Enter Name: ");
    scanf("%s", employees[count].name);
    printf("Enter Salary: ");
    scanf("%f", &employees[count].salary);
    count++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Employee Found: ID=%d, Name=%s, Salary=%.2f\n",
                   employees[i].id, employees[i].name, employees[i].salary);
            return;
        }
    }
    printf("Employee not found.\n");
}

void updateEmployee() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", employees[i].name);
            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee updated successfully!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void deleteEmployee() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

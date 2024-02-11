#include <stdio.h>
#include <stdlib.h>

// Define the structure for employee
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function prototypes
void addEmployee();
void displayEmployees();
void searchEmployee();

int main() {
    int choice;

    do {
        // Display menu
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to add a new employee
void addEmployee() {
    struct Employee emp;
    FILE *file;

    // Open the file in append mode
    file = fopen("data.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Get employee details from user
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    // Write employee details to the file
    fprintf(file, "%d %s %.2f\n", emp.id, emp.name, emp.salary);

    // Close the file
    fclose(file);

    printf("Employee added successfully!\n");
}

// Function to display all employees
void displayEmployees() {
    struct Employee emp;
    FILE *file;

    // Open the file in read mode
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("No employees found.\n");
        return;
    }

    // Read and display employee details from the file
    printf("\nEmployee List:\n");
    while (fscanf(file, "%d %s %f", &emp.id, &emp.name, &emp.salary) != EOF) {
        printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
    }

    // Close the file
    fclose(file);
}

// Function to search for an employee by ID
void searchEmployee() {
    struct Employee emp;
    FILE *file;
    int searchId;
    int found = 0;

    // Open the file in read mode
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("No employees found.\n");
        return;
    }

    // Get employee ID to search for
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);

    // Search for the employee by ID
    while (fscanf(file, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {
        if (emp.id == searchId) {
            printf("Employee found!\n");
            printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }

    // If employee is not found
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }

    // Close the file
    fclose(file);
}
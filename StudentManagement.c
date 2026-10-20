
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("\nStudent database is full!\n");
        return;
    }

    printf("Enter roll number: ");
    if (scanf("%d", &students[count].roll) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].roll == students[count].roll) {
            printf("Roll number already exists!\n");
            return;
        }
    }

    printf("Enter student name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("Enter marks: ");
    if (scanf("%f", &students[count].marks) != 1 ||
        students[count].marks < 0 ||
        students[count].marks > 100) {
        printf("Invalid marks! Enter a value from 0 to 100.\n");
        while (getchar() != '\n');
        return;
    }

    count++;
    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    printf("%-10s %-25s %-10s\n", "Roll No.", "Name", "Marks");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n",
               students[i].roll,
               students[i].name,
               students[i].marks);
    }
}

void searchStudent() {
    int roll;

    printf("Enter roll number to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent found!\n");
            printf("Roll Number: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void updateStudent() {
    int roll;

    printf("Enter roll number to update: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter new name: ");
            scanf(" %49[^\n]", students[i].name);

            printf("Enter new marks: ");
            if (scanf("%f", &students[i].marks) != 1 ||
                students[i].marks < 0 ||
                students[i].marks > 100) {
                printf("Invalid marks!\n");
                while (getchar() != '\n');
                return;
            }

            printf("\nStudent record updated successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

void deleteStudent() {
    int roll;

    printf("Enter roll number to delete: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            printf("\nStudent deleted successfully!\n");
            return;
        }
    }

    printf("\nStudent not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

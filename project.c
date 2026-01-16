/*SCS3/2603/2025
SCS3/150202/2025
SCS3/150322/2025
SCS3/149781/2025*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void addRecord();
void viewRecords();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n===== County Bursary Management System =====\n");
    printf("1. Add student bursary record\n");
    printf("2. View student bursary records\n");
    printf("3. Exit\n");
}

// Function to add a student record to a file
void addRecord() {
    FILE *file;
    char name[50], county[30], institution[50];
    int id;
    float amount;

    file = fopen("bursary_records.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter student full name: ");
    scanf(" %[^\n]", name);

    printf("Enter National ID number: ");
    scanf("%d", &id);

    printf("Enter county of residence: ");
    scanf(" %[^\n]", county);

    printf("Enter institution name: ");
    scanf(" %[^\n]", institution);

    printf("Enter amount awarded (KES): ");
    scanf("%f", &amount);

    fprintf(file, "Name: %s\nID: %d\nCounty: %s\nInstitution: %s\nAmount: %.2f\n\n",
            name, id, county, institution, amount);

    fclose(file);
    printf("Bursary record saved successfully.\n");
}

// Function to view records from the file
void viewRecords() {
    FILE *file;
    char ch;

    file = fopen("bursary_records.txt", "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n===== Bursary Records =====\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

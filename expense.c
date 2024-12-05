#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for date
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

// Structure for salary with date
typedef struct Salary {
    float amount;
    Date date;  // Date of salary (month, year)
} Salary;

// Structure for expense with date
typedef struct Expense {
    char description[100];
    float amount;
    Date date;  // Date of expense (day, month, year)
    struct Expense* next;
} Expense;

// Function prototypes
void addExpense(Expense** head, char* description, float amount, Date date);
void displayExpenses(Expense* head);
float calculateTotal(Expense* head);
void setSalary(Salary* salary, float amount, Date date);
void displaySummary(Salary salary, Expense* expenses);
void suggestInvestment(float savedMoney);

int main() {
    Expense* head = NULL;  // Initialize the linked list for expenses
    Salary salary = {0};   // Initialize salary with zero amount
    int choice;
    char description[100];
    float amount;
    Date date;

    do {
        printf("\n--- Personal Finance Tracker ---\n");
        printf("1. Set Monthly Salary\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter salary amount: ");
                scanf("%f", &amount);
                printf("Enter salary date (month year): ");
                scanf("%d %d", &date.month, &date.year);
                setSalary(&salary, amount, date);
                printf("Salary set successfully!\n");
                break;
            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                printf("Enter expense date (day month year): ");
                scanf("%d %d %d", &date.day, &date.month, &date.year);
                addExpense(&head, description, amount, date);
                printf("Expense added successfully!\n");
                break;
            case 3:
                displaySummary(salary, head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to set the monthly salary
void setSalary(Salary* salary, float amount, Date date) {
    salary->amount = amount;
    salary->date = date;
}

// Function to add an expense to the linked list
void addExpense(Expense** head, char* description, float amount, Date date) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->date = date;
    newExpense->next = NULL;

    if (*head == NULL) {
        *head = newExpense;
    } else {
        Expense* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newExpense;
    }
}

// Function to display the list of expenses
void displayExpenses(Expense* head) {
    if (head == NULL) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    Expense* temp = head;
    while (temp != NULL) {
        printf("Description: %s, Amount: %.2f, Date: %d-%d-%d\n",
               temp->description, temp->amount, temp->date.day, temp->date.month, temp->date.year);
        temp = temp->next;
    }
}

// Function to calculate the total expense
float calculateTotal(Expense* head) {
    float total = 0;
    Expense* temp = head;

    while (temp != NULL) {
        total += temp->amount;
        temp = temp->next;
    }

    return total;
}

// Function to display the summary
void displaySummary(Salary salary, Expense* expenses) {
    if (salary.amount == 0) {
        printf("Salary has not been set yet.\n");
        return;
    }

    printf("\n--- Monthly Summary ---\n");
    printf("Salary: %.2f, Date: %d-%d\n", salary.amount, salary.date.month, salary.date.year);

    float totalExpenses = calculateTotal(expenses);
    printf("Total Expenses: %.2f\n", totalExpenses);

    float savedMoney = salary.amount - totalExpenses;
    if (savedMoney < 0) {
        printf("You have overspent by %.2f this month.\n", -savedMoney);
    } else {
        printf("Saved Money: %.2f\n", savedMoney);
        suggestInvestment(savedMoney);
    }

    displayExpenses(expenses);
}

// Function to suggest investment options
void suggestInvestment(float savedMoney) {
    printf("\n--- Investment Suggestions ---\n");
    printf("You have saved %.2f this month.\n", savedMoney);
    printf("Visit the investment website to explore options: https://your-investment-website.com\n");
}
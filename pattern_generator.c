#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void printRightTriangleStar(int rows);
void printNumberPyramid(int rows);
void printInvertedNumeric(int rows);
void printFloydsTriangle(int rows);
void clearInputBuffer();

int main() {
    int choice, rows;

    do {
        printf("\n=========================================\n");
        printf("        NUMBER PATTERN GENERATOR         \n");
        printf("=========================================\n");
        printf("1. Right-Angled Star Triangle (*)\n");
        printf("2. Centered Number Pyramid (1, 121, 12321)\n");
        printf("3. Inverted Numeric Triangle (54321...)\n");
        printf("4. Floyd's Triangle (1 / 2 3 / 4 5 6)\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter number of rows: ");
            while (scanf("%d", &rows) != 1 || rows <= 0) {
                printf("Please enter a positive integer for rows: ");
                clearInputBuffer();
            }
        }

        switch (choice) {
            case 1:
                printRightTriangleStar(rows);
                break;
            case 2:
                printNumberPyramid(rows);
                break;
            case 3:
                printInvertedNumeric(rows);
                break;
            case 4:
                printFloydsTriangle(rows);
                break;
            case 5:
                printf("Exiting Pattern Generator. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please select between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Option 1: Right-Angled Star Triangle
void printRightTriangleStar(int rows) {
    printf("\n--- Pattern Output ---\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Option 2: Centered Number Pyramid
void printNumberPyramid(int rows) {
    printf("\n--- Pattern Output ---\n");
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int space = 1; space <= rows - i; space++) {
            printf("  ");
        }
        // Print ascending numbers
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        // Print descending numbers
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Option 3: Inverted Numeric Triangle
void printInvertedNumeric(int rows) {
    printf("\n--- Pattern Output ---\n");
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

// Option 4: Floyd's Triangle
void printFloydsTriangle(int rows) {
    int count = 1;
    printf("\n--- Pattern Output ---\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", count++);
        }
        printf("\n");
    }
}

// Utility to flush invalid input
void clearInputBuffer() {
    while (getchar() != '\n');
}
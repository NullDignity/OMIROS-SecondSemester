#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ST_AM 3 // Configurable

void printArray(char array[], int size) {
    int x = 0;
    for (x = 0; x < size; x++) {
        printf("%c", array[x]);
    }
}

void clearBuffer() {
    int x;
    while ((x = getchar()) != '\n' && x != EOF);
}

void swapVathmous(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swapStrings(char* a, char* b) {
    char temp[30];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void taxinomiseVathmous(float grades[], char array1[][30], char array2[][30], int size) {
    int x, y;
    float temp;
    for (x = 0; x < size-1; x++) {
        for (y = 0; y < size - x - 1; y++) {
            if (grades[y] > grades[y+1])
                swapVathmous(&grades[y], &grades[y+1]);
                swapStrings(array1[y], array1[y+1]);
                swapStrings(array2[y], array2[y+1]);
        }
    }
}

void taxinomiseEponima(char array1[][30], char array2[][30], float grades[], int size) {
    int x, y;
    char temp[30];
    for (x = 0; x < size-1; x++) {
        for (y = 0; y < size - x - 1; y++) {
            if (strcmp(array1[y], array1[y+1]) < 0) {
                swapStrings(array1[y], array1[y+1]);
                swapStrings(array2[y], array2[y+1]);
                swapVathmous(&grades[y], &grades[y+1]);
            }
        }
    }
}

int searchName(char* name, char array[][30]) {
    int x;
    for (x = 0; x < ST_AM; x++) {
        if (strcmp(name, array[x]) == 0)
            return x;
    }
    return -1;
}

int main(void) {

    int x;
    float grades[ST_AM];
    char firstnames[ST_AM][30], lastnames[ST_AM][30], sought_firstname[30], sought_lastname[30];

    for (x = 0; x < ST_AM; x++) {
        printf("Please enter Student %d's first name: ", x+1);
        fgets(firstnames[x], 30, stdin);
        printf("Please enter Student %d's last name: ", x+1);
        fgets(lastnames[x], 30, stdin);
        printf("Please enter Student %d's grade: ", x+1);
        scanf("%f", &grades[x]);
        while (grades[x] > 10 || grades[x] < 0) {
            printf("Invalid grade. Please re-enter: ");
            scanf("%f", &grades[x]);
        }
        printf("\n");
        clearBuffer();
    }

    system("cls");
    taxinomiseVathmous(grades, firstnames, lastnames, ST_AM);
    printf("========= ORDERED ASCENDING TO GRADE ==============\n\n");

    for (x = 0; x < ST_AM; x++) {
        printf("=== Student %d ===\n", x+1);
        printf("Last Name: ");
        printArray(lastnames[x], strlen(lastnames[x]));
        printf("First Name: ");
        printArray(firstnames[x], strlen(firstnames[x]));
        printf("Grade: %.1f\n\n", grades[x]);
    }

    printf("========= ORDERED DESCENDING TO NAME ==============\n\n");
    taxinomiseEponima(lastnames, firstnames, grades, ST_AM);

    for (x = 0; x < ST_AM; x++) {
        printf("=== Student %d ===\n", x+1);
        printf("Last Name: ");
        printArray(lastnames[x], strlen(lastnames[x]));
        printf("First Name: ");
        printArray(firstnames[x], strlen(firstnames[x]));
        printf("Grade: %.1f\n\n", grades[x]);
    }

    printf("===================================================\n\n");

    printf("Please enter the first name of the student you are looking for (CASE SENSITIVE): ");
    fgets(sought_firstname, 30, stdin);
    printf("Please enter the last name of the student you are looking for (CASE SENSITIVE): ");
    fgets(sought_lastname, 30, stdin);

    system("cls");

    if (searchName(sought_firstname, firstnames) > -1 && searchName(sought_lastname, lastnames) > -1) {
        printf("First Name: %s", sought_firstname);
        printf("Last Name: %s", sought_lastname);
        printf("Grade: %.1f\n\n", grades[searchName(sought_firstname, firstnames)]);
    } else
        printf("The student could not be found.");

    system("PAUSE");
    return 0;
}

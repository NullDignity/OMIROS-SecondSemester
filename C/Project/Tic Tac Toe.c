#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void clearBuffer() {
    int x;
    while ((x = getchar()) != '\n' && x != EOF);
}

void printScreen(char slots[][3]) {
    printf("Tic-Tac-Toe\n");
    printf("============\n");
    printf(" %c | %c | %c |\n", slots[0][0], slots[0][1], slots[0][2]);
    printf("============\n");
    printf(" %c | %c | %c |\n", slots[1][0], slots[1][1], slots[1][2]);
    printf("============\n");
    printf(" %c | %c | %c |\n\n", slots[2][0], slots[2][1], slots[2][2]);
}

bool victoryCondition(char array[][3], char character) {
    int counter, x, y;

    for (x = 0; x < 3; x++) { // ΟΡΙΖΟΝΤΙΟΣ ΕΛΕΓΧΟΣ
        counter = 0;
        for (y = 0; y < 3; y++) {
            if (array[x][y] == character) {
                counter++;
                if (counter == 3)
                    return 1;
            }
        }
    }

    for (x = 0; x < 3; x++) { // ΚΑΘΕΤΟΣ ΕΛΕΓΧΟΣ
        counter = 0;
        for (y = 0; y < 3; y++) {
            if (array[y][x] == character) {
                counter++;
                if (counter == 3)
                    return 1;
            }
        }
    }

    counter = 0;
    for (x = 0; x < 3; x++) { // ΔΙΑΓΩΝΙΟΣ ΕΛΕΓΧΟΣ
        if (array[x][x] == character) {
            counter++;
            if (counter == 3)
                return 1;
        }
    }

    counter = 0;
    for (x = 0; x < 3; x++) { // ΑΝΤΙΘΕΤΟΣ ΔΙΑΓΟΝΙΟΣ ΕΛΕΓΧΟΣ
        if (array[x][2-x] == character) {
            counter++;
            if (counter == 3)
                return 1;
        }
    }

    return 0;
}

int placeMark(int coordinateX, int coordinateY, char mark, char slots[][3], bool filled[][3]) {
    slots[coordinateX][coordinateY] = mark;
    filled[coordinateX][coordinateY] = 1;
    if (victoryCondition(slots, mark))
        return 1;
    else
        return 0;
}

int filledCoordinate(bool array[][3], int coordinateX, int coordinateY) {
    if (array[coordinateX][coordinateY] == 1)
        return 1;
    return 0;
}

int main() {

    int turn = 0, moves = 0, coordinateX, coordinateY;
    bool gameOver = false, checkPassed;
    bool positions_filled[3][3] = {
        {0, 0, 0},
        {0, 0, 0},  
        {0, 0, 0}
    };
    char input[3], player1_mark[1], player2_mark[1];
    char positions[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    printf("Please select Player 1's mark (O or X): ");
    fgets(input, sizeof(input), stdin);
    while ((input[0] != 'O' && input[0] != 'o') && (input[0] != 'X' && input[0] != 'x')) {
        clearBuffer(); // Ο χρήστης θα χρειαστεί να πατήσει Enter σε περίπτωση λάθους εισαγωγής. Αναγκαίο, και δεν βρήκα κάποιο τρόπο να μην χρειάζεται χωρίς σφάλματα.
        printf("Invalid mark. Please try again (O or X): ");
        fgets(input, sizeof(input), stdin);
    }

    if (input[0] == 'X' || input[0] == 'x') {
        player1_mark[0] = 'X';
        player2_mark[0] = 'O';
    } else {
        player1_mark[0] = 'O';
        player2_mark[0] = 'X';
    }

    system("cls");

    while (!gameOver) {
        
        printScreen(positions);

        checkPassed = false;
        while (!checkPassed) {
            printf("PLAYER %d's TURN\n", turn + 1);
            printf("Please select the horizontal coordinate to place your mark (1~3): ");
            fgets(input, sizeof(input), stdin);
            while (atoi(input) > 3 || atoi(input) < 1) {
                clearBuffer();
                printf("Invalid coordinate. Please try again (1~3): ");
                fgets(input, sizeof(input), stdin);
            }
            coordinateX = atoi(input);
            coordinateX--;

            printf("Please select the vertical coordinate to place your mark (1~3): ");
            fgets(input, sizeof(input), stdin);
            while (atoi(input) > 3 || atoi(input) < 1) {
                clearBuffer();
                printf("Invalid coordinate. Please try again (1~3): ");
                fgets(input, sizeof(input), stdin);
            }
            coordinateY = atoi(input);
            coordinateY--;

            if (!filledCoordinate(positions_filled, coordinateX, coordinateY)) {
                checkPassed = true;
            } else {
                while (!checkPassed) {
                    system("cls");
                    printScreen(positions);
                    printf("The coordinates that you have given were valid, but have already been filled in. Please try again.\n");
                    printf("Please select the horizontal coordinate to place your mark (1~3): ");
                    fgets(input, sizeof(input), stdin);
                    while (atoi(input) > 3 || atoi(input) < 1) {
                        clearBuffer();
                        printf("Invalid coordinate. Please try again (1~3): ");
                        fgets(input, sizeof(input), stdin);
                    }
                    coordinateX = atoi(input);
                    coordinateX--;

                    printf("Please select the vertical coordinate to place your mark (1~3): ");
                    fgets(input, sizeof(input), stdin);
                    while (atoi(input) > 3 || atoi(input) < 1) {
                        clearBuffer();
                        printf("Invalid coordinate. Please try again (1~3): ");
                        fgets(input, sizeof(input), stdin);
                    }
                    coordinateY = atoi(input);
                    coordinateY--;

                    if (!filledCoordinate(positions_filled, coordinateX, coordinateY))
                        checkPassed = true;
                }
            }
        }

        if (turn == 0)
            gameOver = placeMark(coordinateX, coordinateY, *player1_mark, positions, positions_filled);
        else
            gameOver = placeMark(coordinateX, coordinateY, *player2_mark, positions, positions_filled);
        system("cls");

        if (!gameOver) {
            if (turn == 0)
                turn++;
            else
                turn--;
            moves++;
        } else {
            printScreen(positions);
            printf("================\n\n");
            printf("PLAYER %d HAS WON!\n\n", turn+1);
        }

        if (moves == 9) {
            printScreen(positions);
            printf("================\n\n");
            printf("TIE!\n\n");
            break;
        }

    }

    system("PAUSE");
    return 0;
}
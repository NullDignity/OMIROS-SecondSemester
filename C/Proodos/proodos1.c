#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float distance(float input[]) {
    int x;
    float avg = input[0], min = input[0], max = input[0];
    int min_index = 0, max_index = 0;

    for (x = 1; x < 5; x++) {
        avg = avg + input[x];
        if (input[x] < min) {
            min = input[x];
            min_index = x;
        }
        if (input[x] > max) {
            max = input[x];
            max_index = x;
        }
    }
    avg = avg / 5;

    printf("Mininum: %.2f\n", min);
    printf("Maximum: %.2f\n", max);
    printf("Average: %.2f\n", avg);

    int middle_index = (min_index + max_index) / 2;
    float minmid_distance = fabs(middle_index - min_index);
    float maxmid_distance = fabs(middle_index - max_index);

    if (minmid_distance < maxmid_distance)
        return minmid_distance;
    else
        return maxmid_distance;
}

int main(void) {

    int x;
    float numbers[5];

    for (x = 0; x < 5; x++) {
        printf("Please enter number %d: ", x+1);
        scanf("%f", &numbers[x]);
    }

    system("cls");

    float calculated_distance = distance(numbers);

    printf("\nThe shortest distance between the maximum and the middle value is: %.f\n\n", calculated_distance);

	system("pause");
    return 0;
}

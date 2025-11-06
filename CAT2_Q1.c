#include <stdio.h>

int main() {
    // declare and initialize a 2D array
    int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
    };

    // print the elements of the array
    printf("The elements of the array are:\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n"); // move to the next row
    }

    return 0;
}

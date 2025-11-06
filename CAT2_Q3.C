#include <stdio.h>
#include <stdlib.h>

void writeInputFile();
void processInputFile();
void displayFiles();

int main() {
    writeInputFile();
    processInputFile();
    displayFiles();
    return 0;
}

// Function 1: Prompt user for 10 integers and store in input.txt
void writeInputFile() {
    FILE *fptr;
    int i, num;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening input.txt for writing!\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        if (scanf("%d", &num) != 1) {
            printf("Invalid input! Please enter integers only.\n");
            fclose(fptr);
            exit(1);
        }
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("Data successfully written to input.txt\n\n");
}

// Function 2: Read integers from input.txt, calculate sum & average, write to output.txt
void processInputFile() {
    FILE *fin, *fout;
    int num, count = 0, sum = 0;
    float avg;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt for reading!\n");
        exit(1);
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output.txt for writing!\n");
        fclose(fin);
        exit(1);
    }

    while (fscanf(fin, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count == 0) {
        printf("No numbers found in input.txt!\n");
        fclose(fin);
        fclose(fout);
        exit(1);
    }

    avg = (float)sum / count;

    fprintf(fout, "Sum = %d\n", sum);
    fprintf(fout, "Average = %.2f\n", avg);

    fclose(fin);
    fclose(fout);

    printf("Sum and average written to output.txt\n\n");
}

// Function 3: Display contents of input.txt and output.txt
void displayFiles() {
    FILE *fin, *fout;
    int ch;  // <-- FIXED HERE

    printf("---- Contents of input.txt ----\n");
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt!\n");
        exit(1);
    }
    while ((ch = fgetc(fin)) != EOF) {
        putchar(ch);
    }
    fclose(fin);

    printf("\n---- Contents of output.txt ----\n");
    fout = fopen("output.txt", "r");
    if (fout == NULL) {
        printf("Error opening output.txt!\n");
        exit(1);
    }
    while ((ch = fgetc(fout)) != EOF) {
        putchar(ch);
    }
    fclose(fout);
    printf("\n-------------------------------\n");
}


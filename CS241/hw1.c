#include <stdio.h>
#include <stdlib.h>

void readFile(char fileName[]) {
    FILE *fp;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Unable to open file");
        exit(1);
    }

    int num1, num2, num3, num4, num5;
    fscanf(fp, "%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

    fclose(fp);

    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    printf("Number 3: %d\n", num3);
    printf("Number 4: %d\n", num4);
    printf("Number 5: %d\n", num5);
}

int main() {
    printf("File with lines:\n");
    readFile("File_with_numbers_lines.txt");

    printf("File with spaces:\n");
    readFile("File_with_numbers_spaces.txt");

    return 0;
}
/*
============================================================================
Name : 8.c
Author : Nishad Bagade
Question : Write a program to open a file in read only mode, read line by 
           line and display each line as it is read. Close the file when end 
           of file is reached.
Date: 14th - Aug - 2024

Output: 
nishad@nishad-ROG-Zephyrus-G14-GA401QM-GA401QM:~/Desktop/Hand On List 1$ ./8 file_1
Hello, Mr Bruh, I am Nishad
Skibbidi Toilet, Brainrot, Level 7 Gyaat
W Rizz, L Rizz, Sigma Male 
Parent
Child
============================================================================
*/

#include <stdio.h>  // For fopen, fgets, printf, fclose
#include <stdlib.h> // For exit

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[1024];

    // Check if the filename is provided
    if (argc != 2) {
        printf("Usage: ./readfile file_1\n");
        exit(1);
    }

    // Open the file in read-only mode
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the file line by line and display each line
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}

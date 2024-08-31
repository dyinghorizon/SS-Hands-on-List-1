/*
============================================================================
Name : 14.c
Author : Nishad Bagade
Question : Write a program to find the type of a file.
            a. Input should be taken from command line.
            b. program should be able to identify any type of a file.
Date: 14th - Aug - 2024

Output:
nishad@nishad-ROG-Zephyrus-G14-GA401QM-GA401QM:~/Desktop/Hand_On_List_1$ ./14 /home/nishad/Desktop/Hand_On_List_1/f1/f2/hardlink.txt
File: /home/nishad/Desktop/Hand_On_List_1/f1/f2/hardlink.txt
Type: Regular file
nishad@nishad-ROG-Zephyrus-G14-GA401QM-GA401QM:~/Desktop/Hand_On_List_1$ ./14 /home/nishad/Desktop/Hand_On_List_1/f1/f2/myfifo
File: /home/nishad/Desktop/Hand_On_List_1/f1/f2/myfifo
Type: FIFO (named pipe)
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

void print_file_type(struct stat fileStat) {
    if (S_ISREG(fileStat.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return EXIT_FAILURE;
    }

    printf("File: %s\n", argv[1]);
    printf("Type: ");
    print_file_type(fileStat);

    return EXIT_SUCCESS;
}

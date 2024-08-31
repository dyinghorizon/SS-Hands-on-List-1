/*
============================================================================
Name : 27a.c
Author : Nishad Bagade
Description: Write a program to run 
                a. execl

Date: 31nd - Aug - 2024

Output: 
nishad@nishad-ROG-Zephyrus-G14-GA401QM-GA401QM:~/Desktop/Hand_On_List_1$ ./27a
============OUTPUT USING execl===============
-rw-rw-r-- 2 nishad nishad 111 Aug 30 14:59 ./file_1
============================================================================
*/

#include <unistd.h> // Import for `execl` function
#include <stdio.h>  // Import for `printf` function

void main()
{
    char *command_path = "/bin/ls";
    char *options = "-Rl";
    char *file_arg = "./file_1"; // Set if you want to execute `ls` command on a particular file

    printf("============OUTPUT USING execl===============\n");
    execl(command_path, command_path, options, file_arg, NULL);
    printf("\n");
}
/*
============================================================================
Name : 19.c
Author : Nishad Bagade
Question : Write a program to find out time taken to execute getpid system call. 
           Use time stamp counter.
Date: 30th - Aug - 2024

Output:
PID: 9718
Time taken : 25113 
============================================================================
*/

#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     


// Import for __rdtsc()
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

void main()
{
    unsigned int start, end, pid;

    start = __rdtsc();
    pid = getpid();
    end = __rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken : %u \n", (end - start));
}

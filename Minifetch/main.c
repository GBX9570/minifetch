#include <stdio.h> // printf, fopen, fgets, fclose, sscanf, etc etc
#include <stdlib.h> // getenv, malloc, free, atoi, etc etc
#include <string.h> // strlen, strcpy, strstr, strcmp, strtok, memset, etc etc
#include <unistd.h> // gethostname, getlogin, access
#include <sys/utsname.h> // uname
#include "ascii.h"

// init = initialised + used, just a little bit of resource tracking cause i can't do it in my head

typedef struct {
    char os[64]; // init
    char kernel[128]; // init
    char cpu[128]; // init
    long int memsize; // init
    long int meminuse; // init
    long total_mem; // init
    long free_mem; // init
    long int availmem; // init
    char shell[64];
} variables;

int main(void) {
    struct utsname buffer;
    variables var = {0};

    if(uname(&buffer) != 0) {
        perror("uname");
        return 0;
    }

    FILE *meminfo = fopen("/proc/meminfo", "r"); // read /proc/meminfo, in read mode ("r") using the fopen syscall
    if(!meminfo) {
        perror("fopen");    // print system error
        return 1;   // return with an exit code of 1
    }

    char line[256]; // create a buffer that can hold 255 chararcters and have a null terminator (\0)
    while(fgets(line, sizeof(line), meminfo)) {
        // ^^^ the above code reads one line at a time of meminfo (as defined prior) until the EOF
        // what is read is stores in the line variable
        // when it returns NULL, the while loop ends

        if(sscanf(line, "MemTotal: %ld kB", &var.total_mem) == 1) {
            continue;
        }
        if(sscanf(line, "MemFree: %ld kB", &var.free_mem) == 1) {
            continue;
        }
        if(sscanf(line, "MemAvailable: %ld kB", &var.availmem) == 1) {
            break;
        }
        // sscanf scans through line to find MemTotal: (number) kB,
        // if it finds it and the pointer to var.total_mem exists,
        // break and return to the main function
    }

    fclose(meminfo);
    // /proc/meminfo is closed and the file stream is ended

    FILE *distro = fopen("/etc/os-release", "r");
    if(!distro) {
        perror("fopen");
        return 1;
    }

    char line1[256];
    while(fgets(line1, sizeof(line1), distro)) {
        if(strncmp(line1, "PRETTY_NAME=", 12) == 0)  {
            // ^^^ compares the first 12 characters of line1 with 'PRETY_NAME', if
            // PRETTY_NAME is not found then we are not on the right line, if it is then we are
            // on the correct line.
            char *start = strchr(line1, '=');
            // finds the first occurence of '=' in the string.g
            if(start) {
                start++;
                // increment start, meaning that the '=' is skipped.
                start[strcspn(start, "\n")] = 0;
                // find the newline character (\n)
                if(start[0] == '"') {
                    start++;
                    // if the first character of start is a ", increment to next character
                    start[strlen(start) - 1] = 0;
                    // replaces the closing quotation mark with a null terminator.
                }
                strcpy(var.os, start);
                // copy the value of start into var.os
                break;
                // exit the loop
            }
        }
    }

    fclose(distro);

    FILE *cpu = fopen("/proc/cpuinfo", "r");
    if(!cpu) {
        perror("fopen");
        return 1;
    }

    char line2[256];
    while (fgets(line2, sizeof(line2), cpu)) {
            if (sscanf(line2, "model name%*[^:]: %[^\n]", var.cpu) == 1) {
                break;
            }
        }

    fclose(cpu);

        if(strlen(var.cpu) == 0) {
            strcpy(var.cpu, "Unknown CPU");
        }

    printf("\e[1;91mMINIFETCH\n\e[0;37m");
    printf("\e[1;91m---------\n\e[0;37m");
    printf("\e[1;91mKernel:\e[0;37m %s %s\n", buffer.sysname, buffer.release);
    printf("\e[1;91mOperating System:\e[0;37m %s\n", var.os);

        var.memsize = (var.total_mem / 1024);
        printf("\e[1;91mTotal Memory:\e[0;37m %ldMB\n", var.memsize);

        var.meminuse = (((var.total_mem / 1024) - (var.availmem / 1024)));
        printf("\e[1;91mMemory in use:\e[0;37m %ldMB out of %ldMB\n", var.meminuse, var.memsize);
    printf("\e[1;91mCPU:\e[0;37m %s\n", var.cpu);
    ascii(var.os);
}